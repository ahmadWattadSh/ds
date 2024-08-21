# vars
CC=gcc
# CFLAGS will be the options passed to the compiler. -pedantic-errors -Wall -Wextra -Werror -g
CFLAGS=-ansi
#path of header
PATH_HEADER= -I/home/asus/Desktop/Git/ds/pq/header
PATH_HEADER_SECOND = -I/home/asus/Desktop/Git/ds/pq/lib


all: pq.o pq_test.o pq.out 

pq.o: ./src/pq.c  
	$(CC) $(CFLAGS) -c ./src/pq.c $(PATH_HEADER) $(PATH_HEADER_SECOND) -o pq.o

pq_test.o: ./test/pq_test.c
	$(CC) $(CFLAGS) -c ./test/pq_test.c $(PATH_HEADER) $(PATH_HEADER_SECOND) -o pq_test.o

pq.out: pq.o pq_test.o
	$(CC) $(CFLAGS) pq.o pq_test.o -L$(PATH_HEADER_SECOND) -o pq.out ./lib/libsorted_list.a

clean:
	rm *.o *.out
