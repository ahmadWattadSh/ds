# vars
CC=gcc
# CFLAGS will be the options passed to the compiler. -pedantic-errors -Wall -Wextra -Werror -g
CFLAGS=-ansi 
#path of header
PATH_HEADER= -I/home/asus/Desktop/Git/ds/circular_buffer/header

all: c_buff.o c_buff_test.o c_buff.out clean

c_buff.o: ./src/c_buff.c  
	$(CC) $(CFLAGS) -c ./src/c_buff.c $(PATH_HEADER) -o c_buff.o

c_buff_test.o: ./test/c_buff_test.c
	$(CC) $(CFLAGS) -c ./test/c_buff_test.c $(PATH_HEADER) -o c_buff_test.o

c_buff.out: c_buff.o c_buff_test.o
	$(CC) $(CFLAGS) c_buff.o c_buff_test.o -o c_buff.out 

clean:
	rm *.o
