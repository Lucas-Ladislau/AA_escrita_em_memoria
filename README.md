# Escrita em página da memória em C

Este projeto é um programa em C que lê o conteúdo de um arquivo .txt e o mapeia para a memória utilizando a chamada de sistema `mmap`. Ele também exibe o tamanho do arquivo, o tamanho da página de memória do sistema e o número de páginas necessárias para armazenar o arquivo.

## Funcionalidades

- Abre um arquivo especificado pelo usuário.
- Mapeia o conteúdo do arquivo para a memória usando `mmap`.
- Exibe o conteúdo do arquivo no console.
- Exibe informações sobre o tamanho do arquivo, tamanho da página de memória e o número de páginas necessárias.

## Pré-requisitos

Para compilar e executar este programa, você precisará de um ambiente de desenvolvimento C em um sistema Unix-like (Linux, macOS, etc.). Certifique-se de ter o `gcc` (GNU Compiler Collection) instalado.

## Compilação

Para compilar o programa, siga os passos abaixo:

1. Abra um terminal.
2. Navegue até o diretório onde o arquivo fonte `mem.c` está localizado.
3. Execute o comando de compilação:

    ```bash
    gcc -o mem mem.c
    ```

    Este comando compilará o código fonte e gerará um executável chamado `mem`.

## Execução

Para executar o programa, siga os passos abaixo:

1. No terminal, execute o programa passando o nome do arquivo que você deseja visualizar como argumento:

    ```bash
    ./mem <nome_do_arquivo>
    ```

    Substitua `<nome_do_arquivo>` pelo nome do arquivo que você deseja visualizar. Por exemplo:

    ```bash
    ./mem hey.txt
    ```

2. O programa exibirá o conteúdo do arquivo no terminal, além de informações como o tamanho do arquivo, o tamanho da página de memória e o número de páginas necessárias para armazená-lo.

## Exemplo de Saída

Se o arquivo `hey.txt` contiver o texto "Hello, World!", a saída será semelhante a esta:
```bash
Conteúdo do arquivo:
Hello World!
Tamanho do arquivo: 13 bytes
Tamanho da página de memória: 4096 bytes
Número de páginas necessárias: 1
```
