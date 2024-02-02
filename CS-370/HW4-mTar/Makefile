# Created by Rako on 2/03/2024.

CXX = g++
CXXFLAGS = -Wall -g -std=c++11
INCLUDES = -I.
SOURCES = Main.cpp ArchiveUtility.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = mtar

all: $(EXECUTABLE)
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f *.o *~ $(EXECUTABLE)