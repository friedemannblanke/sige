CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra
LDFLAGS = -lm

all: sige.o
	$(CC) $(CFLAGS) sige.o commands.o utils.o -o ./sige

sige.o: sige.c commands.o utils.o
	$(CC) $(CFLAGS) -c sige.c commands.o utils.o

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c utils.h

commands.o: commands.c commands.h
	$(CC) $(CFLAGS) -c commands.c commands.h utils.o

clean:
	rm ./sige *.o *.h.gch
	rm sigefiles/sigedb && touch sigefiles/sigedb
	rm sigefiles/posts/*
