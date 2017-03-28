#ifndef _CFG_H
#define _CFG_H
#include <iostream>
#include "symbol.h"
#include "../structure/genesis.h"

/** The class for the control flow graph, also includes the symbol table */

/* A few important comments:
	 The entry block is the one with the same label as the AST function name.
	   (it could be the first of bbs, or it could be defined by an attribute value)
	 The exit block is the one with both exit pointers equal to nullptr.
     (again it could be identified in a more explicit way)

 */

class CFG {
 public:
	CFG(Genesis* genesis);
	virtual ~CFG();
	virtual std::string toString() const;
	void addBasicBlock(BasicBlock* bb); 
	void addSymbol(Symbol* symbol);
	// symbol table methods
	Symbol* getSymbol(string name);
	std::string getUsableBasicBlockName() const;
	

 protected:
	map <string, Symbol*> symbolsTable;
	BasicBlock* current_bb;
	int nextFreeSymbolIndex; /**< to allocate new symbols in the symbol table */
	int nextBBnumber; /**< just for naming */
	Genesis* genesis;
	vector <BasicBlock*> blocks; /**< all the basic blocks of this CFG*/
};

#endif