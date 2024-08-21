# vars
CC=gcc
# CFLAGS will be the options passed to the compiler. -pedantic-errors -Wall -Wextra -Werror -g
CFLAGS=-ansi
#path of header
PATH_HEADER= -I/home/asus/Desktop/Git/ds/queue/header
PATH_HEADER_SECOND = -I/home/asus/Desktop/Git/ds/queue/include

all: queue.o queue_test.o sll.o queue.out clean

queue.o: ./src/queue.c  
	$(CC) $(CFLAGS) -c ./src/queue.c $(PATH_HEADER) $(PATH_HEADER_SECOND) -o queue.o

queue_test.o: ./test/queue_test.c
	$(CC) $(CFLAGS) -c ./test/queue_test.c $(PATH_HEADER) $(PATH_HEADER_SECOND) -o queue_test.o
	
sll.o: ./include/sll.c
	$(CC) $(CFLAGS) -c ./include/sll.c $(PATH_HEADER_SECOND) -o sll.o	

queue.out: queue.o queue_test.o
	$(CC) $(CFLAGS) queue.o queue_test.o sll.o -o queue.out 

clean:
	rm *.o
