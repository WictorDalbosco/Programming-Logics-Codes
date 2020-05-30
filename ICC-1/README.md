# Introdução a Ciência da Computação I
Esse diretório contêm programas feitos para a disciplina de Introdução a Ciência da Computação do ICMC/USP

## Sobre os projetos:

Os programas deselvolvidos nessa disciplina foram:

**1. Jogo da Velha**<p>
Um jogo da velha com X e O utilizando matrizes

**2. Bar Plot**<p>
Um programa que recebe dados e armazena seus itens mostrando-os em forma de um gráfico de barra de '#' (hash-tags)

**3. Binário para Decimal**<p>
Este programa converte números binários de ate 30 caracteres para decimal

**4. Cifra de César**<p>
Dado uma frase e uma chave, este programa encripta e desencripta mensagens através do método da Cifra de Cesar

**5. Determinante**<p>
Este programa calcula o determinante de matrizes 1x1, 2x2 e 3x3.

**6. Biblioteca**<p>
Simula um sistema simples de aluguel e devolução de livros dada uma 
lista prévia de um acervo bibliográfico de N livros, com limite máximo para empréstimo
de até 10 livros por usuário

**7. Substituir Palavra**<p>
Dada uma palavra, uma frase e uma segunda palavra, será feita uma busca pela frase e então, 
todas as ocorrências da primeira palavra na frase serão 
trocadas pela segunda

**8. Ordenar registros**<p>
Este programa receberá uma lista de registros contendo um nome um número (Nome de filmes e suas respectivas datas de lançamento), e poderá ser feita
uma organização por ordem alfabetica das ocorrências ou ordem numérica


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
os códigos estão bem comentados sobre o que está sendo feito
