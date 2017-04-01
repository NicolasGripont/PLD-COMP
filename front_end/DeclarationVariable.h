#ifndef _DECLARATIONVARIABLE_H
#define _DECLARATIONVARIABLE_H

#include "Printable.h"
#include "IRTranslatable.h"

class DeclarationVariable : public Printable, IRTranslatable
{
public:
    DeclarationVariable(char* _id, bool _array);
    virtual ~DeclarationVariable(); 
    char* getId();	
    bool isArray();
    bool isDeclaration();

    std::string toString() const;

    void buildIR(CFG * cfg) const;

protected:
    char* id;
    bool array;
    bool declaration;

    DeclarationVariable(char* _id, bool _array, bool _declaration);
};

#endif
