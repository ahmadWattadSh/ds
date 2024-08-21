############################# Makefile variables ###############################

# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -fPIC -ansi -O1

# Target
TARGET = hash_table.out

# Objects
OBJS = $(BPATH)hash_table.o

# Shared objects
SOBJS = $(LPATH)libsorted_list.so

# Additional shared library path
libdll_PATH = ./lib/

# Additional shared library flags
libdll_FLAG = -ldll

############################## Custom variables ################################

# Header Path
HPATH = -I ./include

# Bin Path
BPATH = ./bin/

# Src Path
SPATH = ./src/

# Test Path
TPATH = ./test/

# Lib Path
LPATH = ./lib/

################################### RULES ######################################

# Default target
all: $(TARGET)

$(TARGET): $(BPATH)hash_table.o $(BPATH)test_hash_table.o
	$(CC) -g $(CFLAGS) -o $@ $(BPATH)hash_table.o $(BPATH)test_hash_table.o -Wl,-rpath,$(libdll_PATH) -L$(libdll_PATH) $(libdll_FLAG)

$(BPATH)hash_table.o: $(SPATH)hash_table.c
	$(CC) -g $(CFLAGS) -c $<  $(HPATH) -o $@

$(BPATH)test_hash_table.o: $(TPATH)test_hash_table.c
	$(CC) -g $(CFLAGS) -c $<  $(HPATH) -o $@


clear: 
	rm $(BPATH)*.o

run:
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)
