CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra
LDFLAGS = -lm

all: sige.o
	$(CC) $(CFLAGS) sige.o commands.o structs.o -o sige

sige.o: sige.c commands.o structs.o
	$(CC) $(CFLAGS) -c sige.c commands.o structs.o

commands.o: commands.c commands.h structs.h
	$(CC) $(CFLAGS) -c commands.c commands.h structs.o

structs.o: structs.h
	$(CC) $(CFLAGS) -c structs.h

clean:
	rm sige sige.o commands.o commands.h.gch structs.o 
	rm sigefiles/sigedb && touch sigefiles/sigedb
	rm sigefiles/posts/*
