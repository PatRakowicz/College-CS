CXX = g++
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = httpRequester
CXXFLAGS = -Wall -std=c++11

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

clean:
	rm -f $(EXEC) $(OBJ)

.PHONY: all clean
