CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra
LDFLAGS = -lm

all: sige.c
	gcc sige.o -o sige

sige.c: commands.h structs.h

commands.o: structs.h
	gcc -I . -c commands
