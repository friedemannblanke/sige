CC = gcc
CFLAGS = -std=c99 #-pedantic -Wall -Wextra
LDFLAGS = -lm

all: sige.o utils.o
	$(CC) $(CFLAGS) sige.o utils.o -o ./sige

sige.o: sige.c utils.o
	$(CC) $(CFLAGS) -c sige.c utils.o

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c commands.c utils.c utils.h

clean:
	rm ./sige *.o *.h.gch
	rm sigefiles/sigedb && touch sigefiles/sigedb
	rm sigefiles/posts/*
