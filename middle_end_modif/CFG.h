#include <vector>
#include <unordered_map>
#include <string>

#include "../front_end/Genesis.h"
#include "DataType.h"
#include "Symbol.h"

class BasicBlock;

class CFG
{
  public:
    CFG();

    void parseAst(Genesis *ast);
    void parseGlobalDeclarationVariable(GlobalDeclarationVariable *globalDeclarationVariable);
    void parseGlobalDeclarationFunction(DeclarationFunction *DeclarationFunction);

    DataType dataTypeFromInt(int type);

    void addBB(BasicBlock *bb);

    // x86 code generation: could be encapsulated in a processor class in a retargetable compiler
    void genAsm(std::ostream &o);
    std::string IRRegToAsm(std::string reg); /**< helper method: inputs a IR reg or input variable, returns e.g. "-24(%rbp)" for the proper value of 24 */
    void genAsmPrologue(std::ostream &o);
    void genAsmEpilogue(std::ostream &o);

    std::string createNewTempvar(DataType dataType);

    // basic block management
    std::string newBBName();

    Genesis *getAst();
    BasicBlock *getCurrentBB();

  protected:
    Genesis *ast; /**< The AST this CFG comes from */
    BasicBlock *currentBB;

    std::unordered_map<string, Symbol *> functions;
    std::unordered_map<string, Symbol *> variables;

    int nextFreeSymbolIndex;
    int nextTmpVarNumber;
    int nextBBnumber;

    std::vector<BasicBlock *> bbs;
};
