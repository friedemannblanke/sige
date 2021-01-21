CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra
LDFLAGS = -lm

all: sige.o
	$(CC) $(CFLAGS) sige.o commands.o -o sige

sige.o: sige.c commands.h structs.h
	$(CC) $(CFLAGS) -c sige.c

commands.o: commands.h structs.h
	$(CC) $(CFLAGS) -c commands.c

structs.o: structs.h
	$(CC) $(CFLAGS) -c structs.h -o structs.o

clean:
	rm sige sige.o commands.o
	rm sigedb && touch sigedb
