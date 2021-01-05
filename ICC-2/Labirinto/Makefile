all:
	@gcc -o Labirinto Labirinto.c -lm

run:
	@./Labirinto < ./Casos_de_Teste/caso8.in

valgrind:
	@valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./Labirinto < ./Casos_de_Teste/caso8.in