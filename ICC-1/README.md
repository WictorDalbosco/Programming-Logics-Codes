# Introdução a Ciência da Computação I
Esse diretório contêm programas em `c` feitos para a disciplina de Introdução a Ciência da Computação código 0221 da grade curricular obrigatória do curso de Ciências da Computação disponível no [site](https://uspdigital.usp.br/jupiterweb/) da USP.

## Sobre os projetos:

Os programas deselvolvidos nessa disciplina foram:

**1. Jogo da Velha**<p>
Um jogo da velha com X e O utilizando matrizes;

**2. Bar Plot**<p>
Um programa que recebe dados e armazena seus itens mostrando-os em forma de um gráfico de barra de '#' (hash-tags);

**3. Binário para Decimal**<p>
Este programa converte números binários de ate 30 caracteres para decimal;

**4. Cifra de César**<p>
Dado uma frase e uma chave, este programa encripta e desencripta mensagens através do método da Cifra de Cesar;

**5. Determinante**<p>
Este programa calcula o determinante de matrizes 1x1, 2x2 e 3x3;

**6. Biblioteca**<p>
Simula um sistema simples de aluguel e devolução de livros dada uma 
lista prévia de um acervo bibliográfico de N livros, com limite máximo para empréstimo
de até 10 livros por usuário;

**7. Substituir Palavra**<p>
Dada uma palavra, uma frase e uma segunda palavra, será feita uma busca pela frase e então, 
todas as ocorrências da primeira palavra na frase serão 
trocadas pela segunda;

**8. Ordenar registros**<p>
Este programa receberá uma lista de registros contendo um nome um número (Nome de filmes e suas respectivas datas de lançamento), e poderá ser feita
uma organização por ordem alfabetica das ocorrências ou ordem numérica.


## Executando os programas:

1. Para executar os arquivos em c é necessário utilizar um compilador GNU do Linux como o gcc:<p>
```
 $ sudo apt update
 $ sudo apt install gcc
```
2. Depois é necessário fazer a compilação do arquivo que se encontra nas pastas de cada programa:<p>
Caso queira executar o arquivo já existente<p>
```
$ ./nomeExecutavel
```
Ou compilar em um novo arquivo<p>
``` 
$ gcc -o nomeExecutavel nomePrograma.c
```
## Observações:
Os programas não possuem dicas visuais explícitas do que deve ser inserido devido ao fato de termos que submeter
esses códigos à um software adotado pela USP chamado [run.codes](http://www.runc.codes.com) e a saída esperada deve ser totalmente padronizada, porém todos
os códigos estão bem comentados sobre o que está sendo feito.
 
 
 
 # Introduction to Computer Science I
This directory contains programs in `c` made for Introduction to Computer Science subject, code 0221 of the curriculum of the Computer Science course available on the [website](https://uspdigital.usp.br/jupiterweb/) of USP.

## About the projects:

The programs developed in this discipline were:

**1. Tic-Tac-Toe**<p>
A tic-tac-toe game with X and O using matrices;

**2. Bar Plot**<p>
A program that receives data and stores its items showing them in the form of a '#' bar graph (hash-tags);

**3. Binary to Decimal**<p>
This program converts binary numbers of up to 30 characters to decimal;

**4. Cesar cipher**<p>
Given a phrase and a key, this program encrypts and decrypts messages using the Cesar Cipher method;

**5. Determinant**<p>
This program calculates the determinant of matrices 1x1, 2x2 and 3x3;

**6. Library**<p>
Simulates a simple book rental and return system given a
previous list of a bibliographic collection of N books, with a maximum loan limit;
up to 10 books per user

**7. Replace Word**<p>
Given a word, a phrase and a second word, a search for the phrase will be done and then,
all occurrences of the first word in the sentence will be
exchanged for the second;

**8. Sort records**<p>
This program will receive a list of records containing a name and number (name of films and their respective release dates), and can be made
an organization in alphabetical order of occurrences or numerical order.


## Running the programs:

1. To run the files in c it is necessary to use a GNU Linux compiler like gcc: <p>
``
 $ sudo apt update
 $ sudo apt install gcc
``
2. Then it is necessary to compile the file found in the folders of each program: <p>
If you want to run the existing file <p>
``
$ ./ExecutableName
``
Or compile into a new <p> file
``
$ gcc -the ExecutableName ProgramName.c
``
## Comments:
The programs do not have explicit visual cues as to what should be inserted due to the fact that we have to submit
these codes to a software adopted by USP called [run.codes](http://www.runc.codes.com) and the expected output should be fully standardized, but all
the codes are well commented on what is being done.
