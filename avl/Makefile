# vars
CC= gcc -g
# CFLAGS will be the options passed to the compiler. -pedantic-errors -Wall -Wextra -Werror -g
CFLAGS=-ansi 
#path of header
PATH_HEADER= -I/home/asus/Desktop/Git/ds/avl/header

all: avl.o test_avl.o avl.out

avl.o: ./src/avl.c  
	$(CC) $(CFLAGS) -c ./src/avl.c $(PATH_HEADER) -o avl.o

test_avl.o: ./test/test_avl.c
	$(CC) $(CFLAGS) -c ./test/test_avl.c $(PATH_HEADER) -o test_avl.o
	
avl.out: avl.o test_avl.o
	$(CC) $(CFLAGS) avl.o test_avl.o -o avl.out 

clean:
	rm *.o
