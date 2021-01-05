all:
	@gcc -o Spotify Spotify.c -lm -g -Wall -Werror

run:
	@./Spotify

valgrind:
	@valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./Spotify < ./Dataset.in

zip:
	zip -r Spotify.zip Makefile ./Spotify.c 