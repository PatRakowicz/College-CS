CXX = g++
CXXFLAGS = -Wall -std=c++11

all: shell

shell: main.o CommandParser.o Utilities.o
	$(CXX) $(CXXFLAGS) main.o CommandParser.o Utilities.o -o shell

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

CommandParser.o: CommandParser.cpp
	$(CXX) $(CXXFLAGS) -c CommandParser.cpp

Utilities.o: Utilities.cpp
	$(CXX) $(CXXFLAGS) -c Utilities.cpp

clean:
	rm -f *.o shell

