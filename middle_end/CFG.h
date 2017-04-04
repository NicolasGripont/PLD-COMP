#ifndef _CFG_H
#define _CFG_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "Symbol.h"
#include "../front_end/Printable.h"

class Genesis;
class Declaration;
class GlobalDeclarationVariable;
class DeclarationFunction;
class IRInstruction;

class Parser;
class BasicBlock;

/** The class for the control flow graph, also includes the symbol table */

/* A few important comments:
     The entry block is the one with the same label as the AST function name.
       (it could be the first of bbs, or it could be defined by an attribute value)
     The exit block is the one with both exit pointers equal to nullptr.
     (again it could be identified in a more explicit way)

 */

class CFG : public Printable
{
public:

    struct LevelData
    {
        int offset = 0;
        BasicBlock * lastBasicBlock = nullptr;

    };

    CFG(const Parser * parser, DeclarationFunction * _function);
    CFG();
    ~CFG() = default;

    virtual std::string toString() const;

    BasicBlock *createNewBasicBlock(int level, std::string bbName);
    BasicBlock *createNewBasicBlock(int level);
    void addSymbol(Symbol* symbol);

    // symbol table methods
    Symbol * getSymbol(std::string name) const;

    void setLastBasicBlockFromLevel(int level,BasicBlock* block);

    const std::map <std::string, Symbol*> & getSymbolsTable() const;

    std::string getName() const;
    std::string getUsableBasicBlockName();

    void setCurrentBasicBlock(BasicBlock * bb);
    BasicBlock * getCurrentBasicBlock() const;

    Symbol * getLastInstructionDestination();

    int getOffsetFromCurrentBasicBlock() const;
    std::string getTempVariableName();

    void addSymbolToCurrentBasicBlock(Symbol * symbole);

    void setCurrentBasicBlockExitTrue(BasicBlock * bb);
    void setCurrentBasicBlockExitFalse(BasicBlock * bb);
    void addInstructionInCurrentBasicBlock(IRInstruction * instruction);

    void attachNewBasicBlock(BasicBlock * block);

    void setRootBasicBlock(BasicBlock * block);
    BasicBlock * getRootBasicBlock() const;

    LevelData * getLevelData(int level);
    void addNewLevelData(int level, BasicBlock * firstBlock);

private:

    int nextBBnumber;
    int lastBasicBlockLevel;

    DeclarationFunction * function;
    std::map <std::string,Symbol*> symbolsTable;

    BasicBlock * currentBasicBlock;
    BasicBlock * rootBasicBlock;

    std::map <int, LevelData> mapLevelData;   /**< all the basic blocks of this CFG*/

    void cleanLevel(int level);
};

#endif
