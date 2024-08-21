# vars
CC=gcc
# CFLAGS will be the options passed to the compiler. -pedantic-errors -Wall -Wextra -Werror -g
CFLAGS=-ansi
#path of header
PATH_HEADER= -I/home/asus/Desktop/Git/ds/schedular/header
PATH_HEADER_SECOND = -I/home/asus/Desktop/Git/ds/schedular/lib

all: libscheduler_lib.so sched.o sched_test.o sched.out 

dll.o: ../ws8_DLL/src/dll.c
	$(CC) $(CFLAGS) -c -fpic ../ws8_DLL/src/dll.c $(PATH_HEADER_SECOND) -o dll.o
sorted_list.o: ../sorted_list/src/sorted_list.c
	$(CC) $(CFLAGS) -c -fpic ../sorted_list/src/sorted_list.c  $(PATH_HEADER_SECOND) -o sorted_list.o
uid.o: ../uid/src/uid.c
	$(CC) $(CFLAGS) -c -fpic ../uid/src/uid.c $(PATH_HEADER_SECOND) -o uid.o
task.o: ../Task/src/task.c
	$(CC) $(CFLAGS) -c -fpic ../Task/src/task.c $(PATH_HEADER_SECOND) -o task.o
pq.o: ../pq/src/pq.c
	$(CC) $(CFLAGS) -c -fpic ../pq/src/pq.c $(PATH_HEADER_SECOND) -o pq.o

libscheduler_lib.so: ./dll.o ./sorted_list.o ./uid.o ./task.o ./pq.o
	$(CC) $(CFLAGS) -shared -o ./lib/libscheduler_lib.so dll.o sorted_list.o uid.o task.o pq.o 

sched.o: ./src/sched.c  
	$(CC) $(CFLAGS) -c -fpic ./src/sched.c $(PATH_HEADER) $(PATH_HEADER_SECOND) -o sched.o

sched_test.o: ./test/sched_test.c
	$(CC) $(CFLAGS) -c -fpic ./test/sched_test.c $(PATH_HEADER) $(PATH_HEADER_SECOND) -o sched_test.o

sched.out: sched.o sched_test.o libscheduler_lib.so
	$(CC) $(CFLAGS) sched.o sched_test.o -L/lib -o sched.out ./g++  -L/lab -Wl,-rpath,./lab -llab lab2.o -Wl,-rpath,/lib
	
#	$(CC) $(CFLAGS) sched.o sched_test.o -L$(PATH_HEADER_SECOND) -o sched.out ./lib/liball_lib.a
#sched.out: sched.o sched_test.o
#	$(CC) $(CFLAGS) sched.o sched_test.o -L$(PATH_HEADER_SECOND) -o sched.out ./lib/liball_lib.a

cleanobj:
	rm *.o
clean:
	rm *.o *.out *.so
