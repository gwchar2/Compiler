# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g 
LDFLAGS = -L/C/msys64/usr/lib -lfl			# REMEMBER TO KEEP ONLY -lfl WHEN WE ARE HANDING IN THE PROJECT!!!!		

# Directories
SRC_DIR = src
AST_DIR = $(SRC_DIR)/AST
INCLUDE_DIR = include
BUILD_DIR = build

# Output executable
TARGET = cpq.exe

# Source files
MAIN_CPP_SRCS  = $(SRC_DIR)/cpq.cpp \
		   		 $(SRC_DIR)/symbol_table.cpp \
		   		 $(SRC_DIR)/global_scope.cpp 

# AST Directories seperately
AST_BASE_SRCS = $(wildcard $(AST_DIR)/Base/*.cpp)
AST_CONTROL_SRCS = $(wildcard $(AST_DIR)/ControlFlow/*.cpp)
AST_EXPR_SRCS = $(wildcard $(AST_DIR)/Expressions/*.cpp)
AST_STMT_SRCS = $(wildcard $(AST_DIR)/Statements/*.cpp)

# All Source files combined 
CPP_SRCS = $(MAIN_CPP_SRCS) $(AST_BASE_SRCS) $(AST_CONTROL_SRCS) $(AST_EXPR_SRCS) $(AST_STMT_SRCS)				

# Object files from C++ sources
CPP_OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(CPP_SRCS))

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
CPP_OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(CPP_SRCS))
BUILD_DIRS = $(BUILD_DIR) $(BUILD_DIR)/AST/Base $(BUILD_DIR)/AST/ControlFlow \
             $(BUILD_DIR)/AST/Expressions $(BUILD_DIR)/AST/Statements

# Default target
.PHONY: all clean rebuild run
all: $(BUILD_DIR) $(INCLUDE_DIR) $(TARGET)

# Create build directory if it doesn't exist
$(BUILD_DIRS):
	mkdir -p $@

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
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE_PARSER_H) | $(BUILD_DIRS)
	@mkdir -p $(dir $@)
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
	rm -rf $(BUILD_DIR)/AST/Base $(BUILD_DIR)/AST/ControlFlow \
             $(BUILD_DIR)/AST/Expressions $(BUILD_DIR)/AST/Statements 

# Rebuild
rebuild: clean all

# Run with a specific input file
# command: make run [FILE]
# FILE=my_input_file.txt
run: $(TARGET)
	./$(TARGET) $(FILE)

# Run all test files in the test folder and append errors to error.txt
tests: $(TARGET)
	@for file in tests/*.ou; do \
		echo "Running test on $$file"; \
		./$(TARGET) $$file; \
		echo "------------------------------"; \
	done