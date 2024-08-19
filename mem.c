#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Arquivo: %s <nome_do_arquivo>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *nome_arquivo = argv[1];

    int fd = open(nome_arquivo, O_RDONLY);
    if (fd == -1) {
        perror("Erro ao abrir o arquivo");
        return EXIT_FAILURE;
    }

    struct stat st;
    if (fstat(fd, &st) == -1) {
        perror("Erro ao obter informações do arquivo");
        close(fd);
        return EXIT_FAILURE;
    }
    size_t tamanho_arquivo = st.st_size;

    char *mem = mmap(NULL, tamanho_arquivo, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
    if (mem == MAP_FAILED) {
        perror("Erro ao mapear o arquivo");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("Conteúdo do arquivo:\n%s\n", mem);

    if (munmap(mem, tamanho_arquivo) == -1) {
        perror("Erro ao desmapear a memória");
    }
    
    long tamanho_pagina = sysconf(_SC_PAGESIZE);
    size_t num_paginas = (tamanho_arquivo + tamanho_pagina - 1) / tamanho_pagina;

    printf("Tamanho do arquivo: %zu bytes\n", tamanho_arquivo);
    printf("Tamanho da página de memória: %ld bytes\n", tamanho_pagina);
    printf("Número de páginas necessárias: %zu\n", num_paginas);

    close(fd);

    return EXIT_SUCCESS;
}
