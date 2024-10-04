# Makefile to compile the program

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall

# Source files (Add the names as you complete them!)
SRC = classes/program.cpp classes/statementseq.cpp main.cpp parser.cpp scanner.cpp 

# Output executable
TARGET = language

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Clean up the build files
clean:
	del $(TARGET).exe