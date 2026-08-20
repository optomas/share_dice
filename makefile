# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c11
INCLUDES = -Iinclude

# Directories
SRC_DIR = src
BIN_DIR = bin
INC_DIR = include

# Targets
TARGET = $(BIN_DIR)/dice_roll

# Automatically find all .c files in the src directory
SRCS = $(wildcard $(SRC_DIR)/*.c)
# Convert .c file paths to .o file paths
OBJS = $(SRCS:.c=.o)

# Default rule
all: $(TARGET)

# Link the final executable
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(TARGET)

# Compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(SRC_DIR)/*.o
	rm -f $(TARGET)

# Prevent make from treating these as files
.PHONY: all clean

