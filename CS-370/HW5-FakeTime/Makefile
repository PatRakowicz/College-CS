# Created 02/10/24 | Rako

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
TARGET = HW05
SOURCES = main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(TARGET) $(OBJECTS)