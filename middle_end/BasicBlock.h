#ifndef _BASICBLOCK_H
#define _BASICBLOCK_H

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "Symbol.h"

class CFG;
class IRInstruction;

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
    BasicBlock(int lvl, CFG *cfg, std::string entry_label);
    virtual ~BasicBlock();

    std::string toString() const;

    void addIRInstruction(IRInstruction *instruction);
    const BasicBlock *getExitTrue() const;
    const BasicBlock *getExitFalse() const;
    const std::string & getLabel() const;

    const CFG *getCFG() const;

    const std::vector<IRInstruction *> & getInstructions() const;

    // Utilisé dans les tests
    void setExitTrue(BasicBlock *_bbExitTrue);
    void setExitFalse(BasicBlock *_bbExitFalse);

    // Dans un BB prologue, on doit retourner la taille de l'AR de la fonction
	// en octets
    int getPrologMaximalOffset() const;

    const std::map<std::string, const Symbol *> & getLocalSymbolsTable() const;

    void addLocalSymbol(const Symbol * sym);

    int getLevel() const;

protected:
    BasicBlock *exit_true;  /**< pointer to the next basic block, true branch. If nullptr, return from procedure */
    BasicBlock *exit_false; /**< pointer to the next basic block, false branch. If nullptr, the basic block ends with an unconditional jump */
    std::string label;      /**< label of the BB, also will be the label in the generated code */
    int level;
    CFG * cfg;		    /** < the CFG where this block belongs */
    std::vector<IRInstruction *> instructions;
    std::map<std::string, const Symbol*> localSymbolsTable;
};

#endif
