# vars
CC=gcc
# CFLAGS will be the options passed to the compiler. -pedantic-errors -Wall -Wextra -Werror -g
CFLAGS=-ansi
#path of header
PATH_HEADER= -I/home/asus/Desktop/Git/ds/stack/header

all: stack.o stack_test.o stack.out libstack_lib.so clean

stack.o: ./src/stack.c  
	$(CC) $(CFLAGS) -c ./src/stack.c $(PATH_HEADER) -o stack.o

stack_test.o: ./test/stack_test.c
	$(CC) $(CFLAGS) -c ./test/stack_test.c $(PATH_HEADER) -o stack_test.o

stack.out: stack.o stack_test.o
	$(CC) $(CFLAGS) stack.o stack_test.o -o stack.out 

libstack_lib.so: stack.o
	$(CC) $(CFLAGS) -shared -o libstack_lib.so stack.o $(PATH_HEADER)
clean:
	rm *.o
