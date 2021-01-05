all:
	@gcc -o ImagensDigitais ImagensDigitais.c -lm -Wall -Werror

run:
	@./ImagensDigitais

valgrind:
	@valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./ImagensDigitais < ./Casos\ de\ Teste\ -\ [Exercicio\ 2.1]\ Criando\ Imagens\ Digitais/6.in

zip:
	zip -r ImagensDigitais.zip Makefile ./ImagensDigitais.c 