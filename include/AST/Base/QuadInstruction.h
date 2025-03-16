#ifndef QUAD_INSTRUCTION_H
#define QUAD_INSTRUCTION_H
#include "QuadGenerator.h"

enum class QuadOp {
    //A,B,C -> Integers
    // D , E, F -> REAL NUMBERS
    // L -> Jump address
    /* Integer Operations */
    IASN,                                   // A := B
    IPRT,                                   // Print the value of B
    IINP,                                   // Read an integer into A
    IEQL,                                   // If B=C then A:=1 else A:=0
    INQL,                                   // If B<>C then A:=1 else A:=0
    ILSS,                                   // If B<C then A:=1 else A:=0
    IGRT,                                   // If B>C then A:=1 else A:=0
    IADD,                                   // A:=B+C
    ISUB,                                   // A:=B-C
    IMLT,                                   // A:=B*C
    IDIV,                                   // A:=B/C

    RASN,                                   // D := E
    RPRT,                                   // Print the value of E
    RINP,                                   // Read a real into D
    REQL,                                   // If E=F then A:=1 else A:=0
    RNQL,                                   // If E<>F then A:=1 else A:=0
    RLSS,                                   // If E<F then A:=1 else A:=0
    RGRT,                                   // If E>F then A:=1 else A:=0
    RADD,                                   // D:=E+F
    RSUB,                                   // D:=E-F
    RMLT,                                   // D:=E*F
    RDIV,                                   // D:=E/F

    ITOR,                                   // D:= real(B)
    RTOI,                                   // A:= integer(E)

    JUMP,                                   // Jump to Instruction number L
    JMPZ,                                   // If A=0 then jump to instruction number L else continue
    HALT,                                    // Halt
    EMPTY
};

struct QuadInstruction {
    QuadOp op;
    std::string strop;
    std::string result, arg1,arg2;   // operands that will be printed
    
    
    QuadInstruction(QuadOp op, std::string result = "", std::string arg1 = "", std::string arg2 = "") :
        op(op), result(result), arg1(arg1), arg2(arg2) {
            strop = opToString(op);
        }

    void setResult(std::string& jump_address){
        result = jump_address;
    }

    std::string toString() const {
        return (strop + " " + result + " " + arg1 + " " + arg2);
    };

    std::string opToString(QuadOp op) {
        switch (op) {
            case QuadOp::IASN: return "IASN";
            case QuadOp::IPRT: return "IPRT";
            case QuadOp::IINP: return "IINP";
            case QuadOp::IEQL: return "IEQL";
            case QuadOp::INQL: return "INQL";
            case QuadOp::ILSS: return "ILSS";
            case QuadOp::IGRT: return "IGRT";
            case QuadOp::IADD: return "IADD";
            case QuadOp::ISUB: return "ISUB";
            case QuadOp::IMLT: return "IMLT";
            case QuadOp::IDIV: return "IDIV";
            
            case QuadOp::RASN: return "RASN";
            case QuadOp::RPRT: return "RPRT";
            case QuadOp::RINP: return "RINP";
            case QuadOp::REQL: return "REQL";
            case QuadOp::RNQL: return "RNQL";
            case QuadOp::RLSS: return "RLSS";
            case QuadOp::RGRT: return "RGRT";
            case QuadOp::RADD: return "RADD";
            case QuadOp::RSUB: return "RSUB";
            case QuadOp::RMLT: return "RMLT";
            case QuadOp::RDIV: return "RDIV";
            
            case QuadOp::ITOR: return "ITOR";
            case QuadOp::RTOI: return "RTOI";
            
            case QuadOp::JUMP: return "JUMP";
            case QuadOp::JMPZ: return "JMPZ";
            case QuadOp::HALT: return "HALT";
            case QuadOp::EMPTY: return "";
            
            default: return "Unknown";
        }
    }
};

#endif