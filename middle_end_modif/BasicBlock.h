#ifndef BASIC_BLOCK_H
#define BASIC_BLOCK_H

#include <string>

#include "OperationType.h"
#include "DataType.h"
#include "IRInstruction.h"

class CFG;

class BasicBlock
{
  public:
    BasicBlock(CFG *_cfg, string _entryLabel);
    void genAsm(ostream &o); /**< x86 assembly code generation for this basic block (very simple) */

    void addIRInstr(IRInstruction *instr);

    // No encapsulation whatsoever here. Feel free to do better.
    BasicBlock *exitTrue;	   /**< pointer to the next basic block, true branch. If nullptr, return from procedure */
    BasicBlock *exitFalse;	  /**< pointer to the next basic block, false branch. If null_ptr, the basic block ends with an unconditional jump */
    string entryLabel;		    /**< label of the BB, also will be the label in the generated code */
    CFG *cfg;			    /** < the CFG where this block belongs */
    vector<IRInstruction *> instrs; /** < the instructions themselves. */
  protected:
};

#endif