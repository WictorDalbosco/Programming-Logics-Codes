CC=gcc
INCLUDES=./Includes
SOURCES=./Source/*.c
PROG=./spellcheck.c
FLAGS=-Wall -Werror -lm -g
BINARY=./spellcheck

all:
	@$(CC) -o $(BINARY) $(PROG) $(SOURCES) -I$(INCLUDES) $(FLAGS)

run:
	@$(BINARY)

valgrind:
	@valgrind  --track-origins=yes --leak-check=full --show-leak-kinds=all $(BINARY)

zip:
	zip -r spellcheck.zip Source/*.c Includes/*.h Makefile $(PROG)

clean:
	@rm -r *.o