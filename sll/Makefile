# vars
CC=gcc
# CFLAGS will be the options passed to the compiler. -pedantic-errors -Wall -Wextra -Werror -g
CFLAGS=-ansi
#path of header
PATH_HEADER= -I/home/asus/Desktop/Git/ds/sll/header

all: sll.o sll_test.o sll.out clean

sll.o: ./src/sll.c  
	$(CC) $(CFLAGS) -c ./src/sll.c $(PATH_HEADER) -o sll.o

sll_test.o: ./test/sll_test.c
	$(CC) $(CFLAGS) -c ./test/sll_test.c $(PATH_HEADER) -o sll_test.o

sll.out: sll.o sll_test.o
	$(CC) $(CFLAGS) sll.o sll_test.o -o sll.out 

clean:
	rm *.o
