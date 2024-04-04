CXX=g++
CXXFLAGS=-std=c++17 -Wall -pthread
SRCS=main.cpp PasswordGenerator.cpp PasswordCracker.cpp
MAIN=hw12

.PHONY: clean all

all: $(MAIN)
	@echo Compiler named hw12 has been compiled

$(MAIN): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(MAIN) $(SRCS)

clean:
	$(RM) $(MAIN)
