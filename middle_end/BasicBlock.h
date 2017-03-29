#ifndef _BASICBLOCK_H
#define _BASICBLOCK_H

#include <iostream>

#include "IRInstruction.h"
#include "CFG.h"

/**  The class for a basic block */

/* A few important comments.
	 IRInstr has no jump instructions:
	 assembly jumps are generated as follows in BasicBlock::gen_asm():
     1/ a cmp_* comparison instructions, if it is the last instruction of its block, 
       generates an actual assembly comparison followed by a conditional jump to the exit_false branch
			 If it is not the last instruction of its block, it behaves as an arithmetic two-operand instruction (add or mult)
		 2/ BasicBlock::gen_asm() first calls IRInstr::gen_asm() on all its instructions, and then 
		    if  exit_true  is a  nullptr, it generates the epilogue
				if  exit_false is not a nullptr, and the last instruction is not a cmp, it generates two conditional branches based on the value of the last variable assigned 
        otherwise it generates an unconditional jmp to the exit_true branch 
*/

class BasicBlock
{
public:
	BasicBlock(CFG* cfg, string entry_label);
	virtual ~BasicBlock();
	virtual std::string toString() const;
	void addIRInstruction(IRInscruction* instruction);
	BasicBlock* getExitTrue() const;
	BasicBlock* getExitFalse() const;
	std::string getLabel() const;
	CGF* getCFG() const;
	vector<IRInscruction*> getInstructions() const;

protected:
	BasicBlock* exit_true;  /**< pointer to the next basic block, true branch. If nullptr, return from procedure */ 
	BasicBlock* exit_false; /**< pointer to the next basic block, false branch. If nullptr, the basic block ends with an unconditional jump */
	std::string label; /**< label of the BB, also will be the label in the generated code */
	CFG* cfg; /** < the CFG where this block belongs */
	vector<IRInscruction*> instructions;
};

#endif