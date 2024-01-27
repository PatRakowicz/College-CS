CXX=g++
CXXFLAGS=-Wall -std=c++11

all: main

main: main.o mfile.o
	$(CXX) $(CXXFLAGS) -o main main.o mfile.o

main.o: main.cpp mfile.h
	$(CXX) $(CXXFLAGS) -c main.cpp

mfile.o: mfile.cpp mfile.h
	$(CXX) $(CXXFLAGS) -c mfile.cpp

clean:
	rm -f *.o main