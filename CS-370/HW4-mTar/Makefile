# Created by Rako on 2/02/2024.

# Define the compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g

# Define any directories containing header files
INCLUDES = -I.

# Define source files
SOURCES = main.cpp ArchiveUtility.cpp

# Define object files
OBJECTS = $(SOURCES:.cpp=.o)

# Define the executable file name
EXECUTABLE = mytar

# The following part carries out the compilation and linking
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^

.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f *.o *~ $(EXECUTABLE)