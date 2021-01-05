all:
	@gcc -o Cocktail cocktail.c -g

run:
	@./Cocktail

valgrind:
	@valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./Cocktail 