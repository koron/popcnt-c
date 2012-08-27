COMMON_OBJ = popcnt.o popcnt_sse4.o
CC = gcc

build: test1

test1: test1.c $(COMMON_OBJ)
	gcc -o $@ test1.c $(COMMON_OBJ)

asm: popcnt_sse4.s

popcnt_sse4.s: popcnt_sse4.c
	gcc -S -c popcnt_sse4.c

clean:
	rm -f *.o *.s
	rm -f *.exe

.PHONY: clean asm
