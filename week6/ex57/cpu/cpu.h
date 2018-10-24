#ifndef INCLUDED_CPU_
#define INCLUDED_CPU_

#include "../tokenizer/tokenizer.h"     // the Tokenizer s a component of the
                                        // CPU.
#include "../memory/memory.h"

class Memory;                           // Memory only needs to be a declared
                                        // term

class CPU
{
    enum
    {
        NREGISTERS = 5,                 // a..e at indices 0..4, respectively
        LAST_REGISTER = NREGISTERS - 1
    };

    struct Operand
    {
        OperandType type;
        int value;
    };

    void (CPU::* const d_exec[8])() =
    {
        reinterpret_cast<void (CPU::*)()>(&CPU::error),
        &CPU::mov,
        &CPU::add,
        &CPU::sub,
        &CPU::mul,
        &CPU::div,
        &CPU::neg,
        &CPU::dsp
    };

    int (CPU::* const d_deref[3])(int value) =
    {
        &CPU::derefVal,
        &CPU::derefReg,
        &CPU::derefMem
    };

    void (CPU::* const d_sto[2])(int lhsVal, int val) =
    {
        &CPU::storeReg,
        &CPU::storeMem
    };

    Memory &d_memory;
    Tokenizer d_tokenizer;

    int d_register[NREGISTERS];

    public:
        CPU(Memory &memory);
        void run();

    private:
        bool error();                   // show 'syntax error' and prepare for
                                        // the next input line

        bool execute(Opcode opcode);    // perform the matching opcode

                                        // return value or a register's or
                                        // memory location's value
        int dereference(Operand const &value);  
                                        
        bool rvalue(Operand &lhs);      // retrieve an rvalue operand
        bool lvalue(Operand &lhs);      // retrieve an lvalue operand 

                                    // determine 2 operands, lhs must be lval
        bool operands(Operand &lhs, Operand &rhs);
        bool twoOperands(Operand &lhs, int &lhsValue, int &rhsValue);

                                    // store a value in register or memory
        void store(Operand const &lhs, int value);

        void mov();             // assign a value
        void add();             // add values
        void sub();             // subtract values
        void mul();             // multiply values
        void div();             // divide values (remainder: last reg.)
                                // div a b computes a /= b, last reg: %
        void neg();             // negate a value
        void dsp();             // display a value

        int derefVal(int);      // helper function for dereference
        int derefReg(int);      // helper function for dereference
        int derefMem(int);      // helper function for dereference

        void storeReg(int lhsVal, int val);     // helper function for store
        void storeMem(int lhsVal, int val);     // helper function for store
};
        
#endif
