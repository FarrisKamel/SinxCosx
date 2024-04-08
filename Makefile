CC = gcc
CFLAGS = -g -Wall -Wpedantic -std=c17

cosx: cosx.o
cosx.o: cosx.c

.PHONY: clean
clean:
	rm -f *.o a.out core cosx
