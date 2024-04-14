CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
LDFLAGS = -pthread
TARGET = MonteCarloPi
SOURCE = main.cpp

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)

run:
	./$(TARGET) 100000 4 500

.PHONY: all clean run help
