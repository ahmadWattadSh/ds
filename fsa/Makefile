# vars
CC=gcc
# CFLAGS will be the options passed to the compiler. -pedantic-errors -Wall -Wextra -Werror -g
CFLAGS=-ansi 
#path of header
PATH_HEADER= -I/home/asus/Desktop/Git/ds/fsa/header

all: fsa.o fsa_test.o fsa.out

fsa.o: ./src/fsa.c  
	$(CC) $(CFLAGS) -c ./src/fsa.c $(PATH_HEADER) -o fsa.o

fsa_test.o: ./test/fsa_test.c
	$(CC) $(CFLAGS) -c ./test/fsa_test.c $(PATH_HEADER) -o fsa_test.o
	
fsa.out: fsa.o fsa_test.o
	$(CC) $(CFLAGS) fsa.o fsa_test.o -o fsa.out 

clean:
	rm *.o
