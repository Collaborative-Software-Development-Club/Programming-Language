# Makefile to compile the program

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall

# Source files (Add the names as you complete them!)
SRC = classes/program.cpp classes/statementseq.cpp classes/declare.cpp classes/declarenum.cpp classes/statement.cpp classes/assign.cpp classes/print.cpp classes/if.cpp classes/loop.cpp classes/condition.cpp classes/compare.cpp classes/expression.cpp classes/term.cpp classes/factor.cpp main.cpp parser.cpp scanner.cpp 

# Output executable
TARGET = interpreter

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Clean up the build files
clean:
	del $(TARGET).exe