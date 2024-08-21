# vars
CC=gcc
# CFLAGS will be the options passed to the compiler. -pedantic-errors -Wall -Wextra -Werror -g
CFLAGS=-ansi
#path of header
PATH_HEADER= -I/home/asus/Desktop/Git/ds/Task/header
PATH_HEADER_SECOND = -I/home/asus/Desktop/Git/ds/Task/lib


all: task.o task_test.o task.out 

task.o: ./src/task.c  
	$(CC) $(CFLAGS) -c ./src/task.c $(PATH_HEADER) $(PATH_HEADER_SECOND) -o task.o

task_test.o: ./test/task_test.c
	$(CC) $(CFLAGS) -c ./test/task_test.c $(PATH_HEADER) $(PATH_HEADER_SECOND) -o task_test.o

task.out: task.o task_test.o
	$(CC) $(CFLAGS) task.o task_test.o -L$(PATH_HEADER_SECOND) -o task.out ./lib/libuid_lib.a

clean:
	rm *.o *.out
