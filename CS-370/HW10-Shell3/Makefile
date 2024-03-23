# Compiler settings - Can change cc to clang++ or g++ if required
CC=g++
CFLAGS=-Wall

# Target executable name
TARGET=hw10

# Object files
OBJS=main.o execCommand.o

# Default target
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Individual source files
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

execCommand.o: execCommand.cpp
	$(CC) $(CFLAGS) -c execCommand.cpp

# Clean target
clean:
	rm -f $(TARGET) $(OBJS)

# Phony targets
.PHONY: clean