COMMON_OBJ = popcnt.o popcnt_sse4.o popcnt_gnu.o

CC = gcc
CFLAGS = -msse4.2 -O2

build: test1 test2

test1: test1.c $(COMMON_OBJ)
	gcc -o $@ test1.c $(COMMON_OBJ)

test2: test2.c $(COMMON_OBJ)
	gcc -o $@ test2.c $(COMMON_OBJ)

asm: popcnt_sse4.s

popcnt_sse4.s: popcnt_sse4.c
	gcc -S -c popcnt_sse4.c

clean:
	rm -f *.o *.s
	rm -f *.exe

.PHONY: clean asm
