#ifndef _CFG_H
#define _CFG_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "Symbol.h"


class Genesis;
class Declaration;
class GlobalDeclarationVariable;
class DeclarationFunction;

class Parser;
class BasicBlock;

/** The class for the control flow graph, also includes the symbol table */

/* A few important comments:
     The entry block is the one with the same label as the AST function name.
       (it could be the first of bbs, or it could be defined by an attribute value)
     The exit block is the one with both exit pointers equal to nullptr.
     (again it could be identified in a more explicit way)

 */

class CFG
{
public:
    CFG(const Parser * parser, DeclarationFunction * _function);
    CFG();
    ~CFG() = default;

    virtual std::string toString() const;

    BasicBlock *createNewBasicBlock(const std::string & bbName);
    BasicBlock *createNewBasicBlock();
    void addSymbol(Symbol* symbol);

    // symbol table methods
    const Symbol * getSymbol(std::string name) const;

    const std::map <std::string,const Symbol*> * getSymbolTableFromLevel(int level) const;

    const std::map <std::string, const Symbol*> & getSymbolsTable() const;

    std::string getName() const;

    void setCurrentBasicBlock(BasicBlock * bb);
    void setCurrentBasicBlockExitTrue(BasicBlock * bb);
    void setCurrentBasicBlockExitFalse(BasicBlock * bb);


    void setRootBasicBlock(BasicBlock * block);
    const BasicBlock * getRootBasicBlock() const;

private:
    std::string getUsableBasicBlockName();
    int nextBBnumber;    /**< just for naming */

    DeclarationFunction * function;
    std::map <std::string,const Symbol*> symbolsTable;

    BasicBlock * currentBasicBlock;
    BasicBlock * rootBasicBlock;

    std::map <int, BasicBlock*> lastBasicBlockbyLevel;   /**< all the basic blocks of this CFG*/
};

#endif
