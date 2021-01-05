all:
	@gcc -o Merge3Way Merge_Raissa.c -g

run:
	@./Merge3Way

valgrind:
	@valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./Merge3Way