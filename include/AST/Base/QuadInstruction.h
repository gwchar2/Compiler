#ifndef QUAD_INSTRUCTION_H
#define QUAD_INSTRUCTION_H

#include <string>

enum class QuadOp {
    /* Integer Operations */
    IASN,   // A := B
    IPRT,   // Print the value of B
    IINP,   // Read an integer into A
    IEQL,   // If B=C then A:=1 else A:=0
    INQL,   // If B<>C then A:=1 else A:=0
    ILSS,   // If B<C then A:=1 else A:=0
    IGRT,   // If B>C then A:=1 else A:=0
    IADD,   // A:=B+C
    ISUB,   // A:=B-C
    IMLT,   // A:=B*C
    IDIV,   // A:=B/C

    RASN,   // D := E
    RPRT,   // Print the value of E
    RINP,   // Read a real into D
    REQL,   // If E=F then A:=1 else A:=0
    RNQL,   // If E<>F then A:=1 else A:=0
    RLSS,   // If E<F then A:=1 else A:=0
    RGRT,   // If E>F then A:=1 else A:=0
    RADD,   // D:=E+F
    RSUB,   // D:=E-F
    RMLT,   // D:=E*F
    RDIV,   // D:=E/F

    ITOR,   // D:= real(B)
    RTOI,   // A:= integer(E)

    JUMP,   // Jump to Instruction number L
    JMPZ,   // If A=0 then jump to instruction number L else continue
    HALT    // Halt
};

struct TacInstruction {
    QuadOp op;
    str::string result, arg1,arg2   // operands that will be printed

    TacInstruction(QuadOp op, std::string result = "", std::string arg1 = "", std::string arg2 = "") :
        op(op), result(std::move(result)), arg1(std::move(arg1)), arg2(std::move(arg2)) {}

    std::string toString() const ;
};


#endif