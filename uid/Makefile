# vars
CC=gcc
# CFLAGS will be the options passed to the compiler. -pedantic-errors -Wall -Wextra -Werror -g
CFLAGS=-ansi -pedantic-errors -Wextra -Werror -g
#path of header
PATH_HEADER= -I/home/asus/Desktop/Git/ds/uid/header

all: uid.o uid_test.o uid.out libuid_lib.a

uid.o: ./src/uid.c  
	$(CC) $(CFLAGS) -c ./src/uid.c $(PATH_HEADER) -o uid.o

uid_test.o: ./test/uid_test.c
	$(CC) $(CFLAGS) -c ./test/uid_test.c $(PATH_HEADER) -o uid_test.o

uid.out: uid.o uid_test.o
	$(CC) $(CFLAGS) uid.o uid_test.o -o uid.out 

libuid_lib.a: uid.o
	ar rcs libuid_lib.a uid.o;
clean:
	rm *.o *.out *.a
