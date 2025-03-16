# MyCompiler

## 📖 Table of Contents

- [Introduction](#introduction)
- [Features](#🚀-features)
- [Project Structure](#📂-project-structure)
- [Installation & Setup](#🛠️-installation--setup)
  - [Requirements](#requirements)
  - [Compilation & Running](#compilation--running)
  - [Usage Examples](#usage-examples)
- [Language Specification](#cpl-language-specification)
  - [Lexical Structure](#1-lexical-structure)
    - [Reserved Keywords](#reserved-keywords)
    - [Symbols](#symbols)
    - [Operators](#operators)
    - [Identifiers & Numbers](#additional-tokens)
    - [Comments & Whitespace](#notes)
  - [Semantic Rules](#2-semantics)
    - [Data Types](#numeric-constants)
    - [Type Casting](#arithmetic-operators)
    - [Assignment Rules](#assignment-rules)
    - [Control Flow](#control-flow)
    - [Example Code](#🔀-example-input-code)
- [Quad Language Specification](#quad-instruction-set)
  - [OpCode Table](#opcode-table)
- [Compiler Details](#compiler-details)
  -[Compilation Process](#compilation-process)
    - [Lexing](#lexing)
    - [Parsing](#parsing)
    - [AST Generation](#ast-generation)
    - [TAC Generation](#tac-generation)
    - [Optimizations](#optimizations)
- [Code Examples](#code-examples)
  - [Source Code Example](#source-code-example)
  - [Generated Tokens (Lexing Output)](#generated-tokens-lexing-output)
  - [AST Representation](#ast-representation)
  - [TAC (Three-Address Code)](#tac-three-address-code)
  - [Final Output](#final-output)
- [Error Handling](#error-handling)
  - [Error Codes](#error-codes)
  - [Warnings](#warnings)
  - [Syntax Errors](#syntax-errors)
- [Optimization Techniques](#optimization-techniques)
  - [Constant Folding - TBD](#constant-folding)
  - [Dead Code Elimination - TBD](#dead-code-elimination)
  - [Register Allocation](#register-allocation)
- [Testing](#testing)
  - [How to Run Tests](#how-to-run-tests)
  - [Example Test Cases](#example-test-cases)

---

## Introduction
A custom compiler built with **Flex & Bison (C++)**, generating **Three-Address Code (TAC)** for intermediate representation in a custom language (Quad).

## 🚀 Features

- **Lexer & Parser:** Built using Flex and Bison.
- **AST Representation:** A structured Abstract Syntax Tree (AST) for syntax analysis.
- **TAC Generation:** Generates three-address code (Quad Code) using `QuadGenerator` (private implementation).
- **Error Handling:** Reports syntax and semantic errors with structured messages.
- **Optimizations:** Implements **temporary variable reuse** for efficiency.

## 📂 Project Structure

```
MyCompiler/
│── src/
│   ├── cpq.cpp                                     # Compiler entry point
│   ├── lexer.l                                     # Flex lexer definition
│   ├── parser.y                                    # Bison grammar definition
│   ├── global_scope.cpp                            # Global scope implementations
│   ├── symbol_table.cpp                            # Symbol table implementations
│   ├── AST/
│   │   ├── Base/                                   # Base AST node class
│   │   │   ├── ASTNode.cpp                         # Main node-type implementation.
│   │   │   ├── QuadGenerator.cpp                   # TAC Generator
│   │   │   ├── SemanticChecker.cpp                 # Semantic Analysis 
│   │   ├── ControlFlow/                            # ControlFlow nodes
│   │   │   ├── ASTBreakNode.cpp                    # AST Node for Break statements
│   │   │   ├── ASTCaseListNode.cpp                 # AST Node for Case statements
│   │   │   ├── ASTIfNode.cpp                       # AST Node for If-Else statements
│   │   │   ├── ASTSwitchNode.cpp                   # AST Node for Switch statements
│   │   │   ├── ASTWhileNode.cpp                    # AST Node for While statements
│   │   ├── Expressions/                            # Expression nodes
│   │   │   ├── ASTBinaryExprNode.cpp               # Binary expression nodes (2 or more operands)
│   │   │   ├── ASTCastExprNode.cpp                 # Casting nodes
│   │   │   ├── ASTIdentifier.cpp                   # ID nodes
│   │   │   ├── ASTLiteralNode.cpp                  # Literal (Immediate) nodes
│   │   │   ├── ASTUnaryExprNode.cpp                # Unary expression nodes
│   │   ├── Statements/                             # Statement nodes
│   │   │   ├── ASTAssignNode.cpp                   # Assignment nodes
│   │   │   ├── ASTBlockNode.cpp                    # Code-Block nodes
│   │   │   ├── ASTInputNode.cpp                    # Input nodes
│   │   │   ├── ASTOutputNode.cpp                   # Output nodes
│   │   │   ├── ASTProgramRoot.cpp                  # Program Root node
│   │   │   ├── ASTStatementListNode.cpp            # Statement list node (Inside a code block)
│── include/                                        # Header files
│── tests/                                          # Sample test cases
│── docs/                                           # Documentation
│── Makefile                                        # Build automation
│── README.md                                       # Project documentation
```

## 🛠️ Installation & Setup

### Requirements
- C++17 or later
- GNU Make
- Flex & Bison 
    Installable from [Here](#https://github.com/lexxmark/winflexbison/releases)
    Or via MSYS2 (Windows)
```sh
    pacman -S mingw-w64-x86_64-flex mingw-w64-x86_64-bison
```

### Compilation & Running
```sh
make
```

### Run the Compiler
```sh
./cpq input_file
```

# CPL Language Specification

## 1. Lexical Structure

### Reserved Keywords:
```
break case default else float if input int output switch while
```

### Symbols:
```
( ) { } , : ; =
```

### Operators:
```
RELOP: == | != | < | > | >= | <=
ADDOP: + | -
MULOP: * | /
OR: ||
AND: &&
NOT: !
CAST: cast<int> cast<float>
```

### Additional Tokens:
```
ID: letter (letter|digit)*
NUM: digit+ | digit+.digit*
```

### Definitions:
- `digit`: `0 | 1 | ... | 9`
- `letter`: `a | b | ... | z | A | B | ... | Z`

### Notes:
1. Whitespace characters such as spaces (` `), tabs (`\t`), and newlines (`\n`) may appear between tokens. They are mandatory where needed for separation (e.g., between a keyword and an identifier) but optional elsewhere.
2. Comments are written between `/* ... */` and do not support nesting.
3. The language is **case-sensitive**.

## 2. Semantics

### Numeric Constants:
- Integer constants (without a decimal point) are of type `int`.
- Floating-point constants (with a decimal point) are of type `float`.

### Arithmetic Operators:
- If at least one operand is `float`, the result is `float`.
- If both operands are `int`, the result is `int`.
- When an operation involves mixed types (`int` and `float`), the `int` operand is converted to `float` before execution.

### Assignment Rules:
- Variables must be **declared before use**.
- Integer division results in the **integer quotient** (like C).
- Assignments are valid if both sides have the same type **or** the left-hand side is `float` and the right-hand side is `int` (implicit conversion to `float`).

### Control Flow:
- The `break` statement is only valid inside a `while` loop or `switch` case (same as C).
- If a `break` is omitted in a `switch-case`, execution continues to the next `case`.
- The expression following `switch` **must be an `int`**, and all `case` labels **must be integers**.

### Type Casting:
- `cast<int>` converts a value to `int`.
- `cast<float>` converts a value to `float`.


## 🔀 Example Input Code
```c
/* Finding minimum between two numbers */
a,b : float;
{
  input(a);
  input(b);
  if (a < b)
    output(a)
  else
    output(b)
}
```

# Quad Instruction Set

## **Operand Notation**
- `A` - Integer variable
- `B, C` - Integer variables or constants
- `D` - Real (floating-point) variable
- `E, F` - Real variables or constants
- `L` - Jump target (line number)

> **Note:** The actual variable names in the program should be written in **lowercase**, and may include **letters, digits, and underscores (`_`)**.

## **Opcode Table**

| **Opcode** | **Arguments**  | **Description** |
|-----------|---------------|----------------|
| **IASN**  | `A B`         | `A := B` (Assign `B` to `A`) |
| **IPRT**  | `B`           | Print the value of `B` |
| **IINP**  | `A`           | Read an integer into `A` |
| **IEQL**  | `A B C`       | If `B = C` then `A := 1` else `A := 0` |
| **INQL**  | `A B C`       | If `B ≠ C` then `A := 1` else `A := 0` |
| **ILSS**  | `A B C`       | If `B < C` then `A := 1` else `A := 0` |
| **IGRT**  | `A B C`       | If `B > C` then `A := 1` else `A := 0` |
| **IADD**  | `A B C`       | `A := B + C` |
| **ISUB**  | `A B C`       | `A := B - C` |
| **IMLT**  | `A B C`       | `A := B * C` |
| **IDIV**  | `A B C`       | `A := B / C` |
| **RASN**  | `D E`         | `D := E` (Assign `E` to `D`) |
| **RPRT**  | `E`           | Print the value of `E` |
| **RINP**  | `D`           | Read a real (floating-point) number into `D` |
| **REQL**  | `A E F`       | If `E = F` then `A := 1` else `A := 0` |
| **RNQL**  | `A E F`       | If `E ≠ F` then `A := 1` else `A := 0` |
| **RLSS**  | `A E F`       | If `E < F` then `A := 1` else `A := 0` |
| **RGRT**  | `A E F`       | If `E > F` then `A := 1` else `A := 0` |
| **RADD**  | `D E F`       | `D := E + F` |
| **RSUB**  | `D E F`       | `D := E - F` |
| **RMLT**  | `D E F`       | `D := E * F` |
| **RDIV**  | `D E F`       | `D := E / F` |
| **ITOR**  | `D B`         | Convert `B` (integer) to `D` (real) |
| **RTOI**  | `A E`         | Convert `E` (real) to `A` (integer) |
| **JUMP**  | `L`           | Jump to instruction `L` |
| **JMPZ**  | `L A`         | If `A = 0`, jump to instruction `L`, else continue execution |
| **HALT**  | -             | Stop execution immediately |

This **Quad Instruction Set** defines all available **intermediate representation (TAC) operations** used in the compiler.


# Compiler Details

## Compilation Process

### Lexing
Lexing (also called scanning) is the first stage of compilation, where the source code is transformed into tokens. The **Flex lexer** reads the input and classifies words based on the defined lexical rules.

#### Example Input:
```c
if (x > 5) output(x);
```

#### Generated Tokens:
```
IF ( ID > NUM ) OUTPUT ( ID ) ;
```

### Parsing
Parsing is the process of analyzing the token sequence to ensure that it follows the grammar rules of the language. This phase constructs a **parse tree** or an **AST (Abstract Syntax Tree)**.

#### Example Parse Tree:
```
IfStmt
├── Condition: >
│   ├── ID: x
│   └── NUM: 5
└── Body:
    └── OutputStmt
        └── ID: x
```

### AST Generation
The Abstract Syntax Tree (AST) is a structured, tree-like representation of the program after parsing. It simplifies later stages of compilation.

#### Example AST for `y = x + 3 * 2;`
```
Assign
├── ID: y
└── BinaryExpr: +
    ├── ID: x
    └── BinaryExpr: *
        ├── NUM: 3
        └── NUM: 2
```

### TAC Generation
Three-Address Code (TAC) is an intermediate representation of the source code that simplifies later translation to machine code. TAC instructions use a compact format, often relying on temporary variables.

#### Example TAC for `y = x + 3 * 2;`
```assembly
IASN t0 3
IASN t1 2
IMUL t3 t0 t1
IADD t4 x t3
IASN y t4
```

### Optimizations
Code optimizations help improve efficiency by reducing redundancy, minimizing memory usage, and enhancing execution speed.

## Code Examples

### Source Code Example
```c
x : int;
{
  x = 5;
  if (x > 2){
    output(x)
  }
  else {}
}
```

### Generated Tokens (Lexing Output)
```
ID INT;
ID = NUM;
IF ( ID > NUM ) {
  OUTPUT ( ID );
} 
else {}
```

### AST Representation
```
IfStmt
├── Condition: >
│   ├── ID: x
│   └── NUM: 2
└── Body:
    └── OutputStmt
        └── ID: x
```

### TAC (Three-Address Code)
```assembly
IASN t0 5 
IASN x 5 
IASN t0 2 
IGRT t1 x t0
JMPZ 8 t1 
IPRT x  
JUMP 8  
HALT   
```

### Final Output
```
5
```


## Error Handling

### Error Codes
The following error codes are defined in the compiler:
```cpp
enum class ErrorCode {
    ERR_NO_FILE_FOUND,
    ERR_FILE_CANT_BE_OPENED,
    ERR_FILE_CANT_BE_READ,
    ERR_NESTED_COMMENTS,
    ERR_UNTERMINATED_COMMENT,
    ERR_TOKEN_INVALID,
    ERR_NO_SUCH_VARIABLE,
    ERR_MISSING_CONDITION,
    ERR_MISSING_MAIN_CASE,
    ERR_CASE_ISNT_INT,
    ERR_MISSING_CASE_NUMBER,
    ERR_SWITCH_NO_DEFAULT,
    ERR_OP_REQUIRES_TWO,
    ERR_COMPARING_FI,
    ERR_MISSING_EXPRESSION,
    ERR_BREAK_OUTSIDE_WHILE,
    ERR_PARSER,
    ERR_MISSING_INPUT,
};
```

### Warnings
In addition to errors, the compiler issues warnings for operations involving **mixed `int` and `float` types**.
#### Example Warning:
```c
int x;
x = 3.5 + 2;
```
**Warning Output:**
```
Warning: Performing action between int and float (Will be assigned FLOAT automatically).
```

### Syntax Errors
Errors that occur due to incorrect structure in the source code.
#### Example:
```c
if x > 5) output(x);
```
**Error Output:**
```
Syntax Error: Unexpected token 'x'. Expected '('.
```


## Optimization Techniques

### Constant Folding - TBD - NOT YET IMPLEMENTED!
Replaces constant expressions with precomputed values.
#### Example:
```c
y = 3 + 2;
```
**Optimized TAC:**
```assembly
IASN y, 5
```

### Dead Code Elimination - TBD - NOT YET IMPLEMENTED!
Removes unused or unreachable code.
#### Example:
```c
x = 5;
x = 6;
```
**Optimized TAC:**
```assembly
IASN x, 6
```

### Register Allocation
Minimizes the number of memory accesses by keeping variables in registers.

## Testing

### How to Run Tests
Predefined tests can be found in dir/tests folder of the project.
In order to run one test you can use the command :

```sh
cpq [file name]
```

In order to run all tests in the folder, you can use the command :
```sh
make tests
```

## 🏗️ Future Improvements
- **Code Optimizations:** Constant folding, dead code elimination, and register allocation
- **Backend Integration:** Convert TAC to machine code
- **More Language Features:** Support for arrays and functions
