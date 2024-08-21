# vars
CC=gcc
# CFLAGS will be the options passed to the compiler. -pedantic-errors -Wall -Wextra -Werror -g
CFLAGS=-ansi -pedantic-errors -Wall -Wextra -Werror -g
#path of header
PATH_HEADER= -I/home/asus/Desktop/Git/ds/knight_tour/header

all: knight_tour.o knight_tour_test.o knight_tour.out

knight_tour.o: ./src/knight_tour.c  
	$(CC) $(CFLAGS) -c ./src/knight_tour.c $(PATH_HEADER) -o knight_tour.o

knight_tour_test.o: ./test/knight_tour_test.c
	$(CC) $(CFLAGS) -c ./test/knight_tour_test.c $(PATH_HEADER) -o knight_tour_test.o
	
knight_tour.out: knight_tour.o knight_tour_test.o
	$(CC) $(CFLAGS) knight_tour.o knight_tour_test.o -o knight_tour.out 

clean:
	rm *.o
	
	
	
make: *** No rule to make target 'test/knight_tour_test.c', needed by 'knight_tour_test.o'.  Stop.
	
	
