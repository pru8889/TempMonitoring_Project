# Compiler
CC = clang

# Compiler flags
CFLAGS = -Wall -Wextra -g -I./include

# Target executable
TARGET = hello

# Build target
all: $(TARGET)

$(TARGET): hello.c
	$(CC) $(CFLAGS) -o $(TARGET) hello.c

# Clean build files
clean:
	rm -f $(TARGET)
