# vars
CC=gcc
# CFLAGS will be the options passed to the compiler. -pedantic-errors -Wall -Wextra -Werror -g
CFLAGS=-ansi 
#path of header
PATH_HEADER= -I/home/asus/Desktop/Git/ds/bst/header

all: bst.o bst_test.o bst.out

bst.o: ./src/bst.c  
	$(CC) $(CFLAGS) -c ./src/bst.c $(PATH_HEADER) -o bst.o

bst_test.o: ./test/bst_test.c
	$(CC) $(CFLAGS) -c ./test/bst_test.c $(PATH_HEADER) -o bst_test.o
	
bst.out: bst.o bst_test.o
	$(CC) $(CFLAGS) bst.o bst_test.o -o bst.out 

clean:
	rm *.o
