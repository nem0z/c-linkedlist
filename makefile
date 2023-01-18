CC=gcc
CFLAGS=-I.

main: main.c
	$(CC) -o main.out main.c $(CFLAGS) linkedlist/*/*.c -I linkedlist

clean:
	rm -f main