## Projeto da 3 unidade

### Aluno: Rafael Rosendo Faustino
### EDB2 - 2024.2
### Horário: T56
### Professor: EINSTEIN GOMES DOS SANTOS


### Introdução

Esse projeto consiste em um sistema fim a fim no qual dado dois arquivos sendo um contendo uma lista de palavras disponíveis e outro arquivo contendo um tabuleiro de letras sendo de tamanho específico NxN
O sistema deve ser capaz de encontrar todas as palavras disponíveis no tabuleiro de letras, sendo que as palavras podem ser formadas a partir de qualquer letra do tabuleiro, e a partir de qualquer direção (horizontal, vertical, diagonal).


### Implementação

O projeto foi implementado utilizando C, com a organização em múltiplos arquivos de extensão .c (implementação) e .h (cabeçalho).
As principais estruturas de dados utilizadas foram:

    Árvore AVL: Para armazenar e ordenar as palavras encontradas no tabuleiro.
    Árvore Trie: Para representar eficientemente os caracteres das palavras do arquivo palavras.txt.

O processo envolve:

    Gerenciamento de memória manual: Um desafio comum em linguagens de baixo nível como C.
    Algoritmo de busca: Explora todas as direções possíveis no tabuleiro e utiliza a Trie para validar se uma sequência de caracteres forma uma palavra válida.
    Inserção na AVL: As palavras validadas pela Trie são armazenadas em ordem alfabética na AVL.


### Workflow

O workflow principal ocorre na função main, que apresenta um menu interativo para o usuário. As opções incluem:

    Carregar arquivos de entrada.
    Processar o tabuleiro e encontrar palavras.
    Visualizar a Trie e a AVL.

O fluxo do jogo é controlado pela função fluxoJogo, que coordena:

    A leitura e validação dos arquivos de entrada.
    O processamento do tabuleiro.
    A interação com as árvores Trie e AVL.

Além disso, o projeto utiliza um Makefile para facilitar a compilação, exigindo apenas que o usuário forneça os arquivos de entrada e execute o programa.

### Dificuldades

1. Gerenciamento de memória

    Trabalhar com múltiplos arquivos e referências cruzadas demandou um cuidado extra, especialmente ao utilizar ponteiros duplos para modificar a raiz das árvores.

2. Criação de funções auxiliares

    Conversão de letras maiúsculas para minúsculas.
    Validação de palavras e sua correta inserção na Trie.
    Navegação e busca eficiente no tabuleiro.

3. Debugging

    Foram utilizados GDB e Valgrind para localizar problemas como segmentation faults e vazamentos de memória, o que proporcionou aprendizado significativo na depuração de código em C.



### Instruções

Para executar o projeto, siga os passos abaixo:

    Certifique-se de que os arquivos de entrada estão no diretório local do projeto:
        palavras.txt: Contendo a lista de palavras.
        tabuleiro.txt: Representando o tabuleiro de letras.

    Compile e execute o programa com o comando:

    make run

O programa irá iniciar e apresentar o menu interativo para continuar o fluxo.
