# vars
CC=gcc
CFLAGS= -ansi -pedantic-errors -Wextra -Werror -g
LDFLAGS :=

# Define source and object directories
SRC_DIR := src
TEST_DIR := test
OBJ_DIR := obj
header := -Iheader
HEADER := -I/home/asus/Desktop/Git/ds/dll/header
# Define source files
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
TEST_FILES := $(wildcard $(TEST_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES)) $(patsubst $(TEST_DIR)/%.c,$(OBJ_DIR)/%.o,$(TEST_FILES))

# Define the target executable
TARGET := myprogram 

# Phony targets
.PHONY: all clean

# Default target
all: $(TARGET) libdll_lib.so

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -fpic  $(header) -c $< -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -fpic  $(header) -c $< -o $@

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

libdll_lib.so: $(OBJ_FILES)
	$(CC) $(CFLAGS) -shared -o libdll_lib.so obj/dll.o $(HEADER)
#libdll.so: $(OBJ_FILES)
#	$(CC) $(CFLAGS) -shared -o $@  $^
# Create the object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean up object files and the executable
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

