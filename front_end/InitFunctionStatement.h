#ifndef _INITFUNCTIONSTATEMENT_H
#define _INITFUNCTIONSTATEMENT_H

#include "DeclarationFunctionStatement.h"
#include "MultipleStatement.h"

// Initialisation du corps de la fonction
class InitFunctionStatement : public DeclarationFunctionStatement
{
public:
    InitFunctionStatement(MultipleStatement* _multipleStatement);
    virtual ~InitFunctionStatement();

    virtual std::string toString() const;
    virtual void buildIR(CFG * cfg) const;

    int countStatements();
    SimpleStatement*& operator[] (int i);

private:
    MultipleStatement* multipleStatement;
};

#endif
