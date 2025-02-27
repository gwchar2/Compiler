# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g
LDFLAGS = -L/C/msys64/usr/lib -lfl

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Output executable
TARGET = compiler.exe

# Source files
CPP_SRCS = $(SRC_DIR)/main.cpp \
           $(SRC_DIR)/functionHelpers.cpp \
           $(SRC_DIR)/errorHandler.cpp \
		   $(SRC_DIR)/symbol_table.cpp

# Object files from C++ sources
CPP_OBJS = $(BUILD_DIR)/main.o \
           $(BUILD_DIR)/functionHelpers.o \
           $(BUILD_DIR)/errorHandler.o \
	       $(BUILD_DIR)/symbol_table.o

# Generated files
PARSER_C = $(BUILD_DIR)/parser.tab.c
PARSER_H = $(BUILD_DIR)/parser.tab.h
INCLUDE_PARSER_H = $(INCLUDE_DIR)/parser.tab.h
LEX_C = $(BUILD_DIR)/lex.yy.c

# Object files from generated sources
PARSER_OBJ = $(BUILD_DIR)/parser.tab.o
LEX_OBJ = $(BUILD_DIR)/lex.yy.o

# All object files
OBJS = $(CPP_OBJS) $(PARSER_OBJ) $(LEX_OBJ)

# Default target
.PHONY: all clean rebuild run
all: $(BUILD_DIR) $(INCLUDE_DIR) $(TARGET)

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Create include directory if it doesn't exist
$(INCLUDE_DIR):
	mkdir -p $(INCLUDE_DIR)

# Generate parser first - it's needed by other files
$(PARSER_C) $(PARSER_H): $(SRC_DIR)/parser.y | $(BUILD_DIR)
	bison -d -o $(PARSER_C) $<

# Copy parser header to include directory
$(INCLUDE_PARSER_H): $(PARSER_H) | $(INCLUDE_DIR)
	mv $(PARSER_H) $(INCLUDE_DIR)/

# Generate lexer
$(LEX_C): $(SRC_DIR)/lexer.l | $(BUILD_DIR)
	flex -o $@ $<

# Compile C++ files - they need the parser header
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE_PARSER_H) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Compile lexer
$(LEX_OBJ): $(LEX_C) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Compile parser
$(PARSER_OBJ): $(PARSER_C) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Link everything
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Clean
clean:
	rm -f $(TARGET)
	rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/*.c $(BUILD_DIR)/*.h
	rm -f $(INCLUDE_DIR)/parser.tab.h

# Rebuild
rebuild: clean all

# Run with a specific input file
# make run FILE=my_input_file.txt
run: $(TARGET)
	./$(TARGET) $(FILE)

# Run all test files in the test folder and append errors to error.txt
tests: $(TARGET)
	@> error.txt  # Clear the error.txt file before appending
	@for file in Tests/*.cpl; do \
		echo "Running test on $$file" >> error.txt; \
		./$(TARGET) $$file >> error.txt 2>&1; \
		echo "------------------------------" >> error.txt; \
	done