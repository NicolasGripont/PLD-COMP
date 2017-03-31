#ifndef _DECLARATIONVARIABLE_H
#define _DECLARATIONVARIABLE_H

#include "Printable.h"

class DeclarationVariable : public Printable
{
public:
    DeclarationVariable(char* _id, bool _array);
    virtual ~DeclarationVariable(); 
    char* getId();	
    bool isArray();
    bool isDeclaration();
	virtual std::string toString() const;

protected:
    char* id;
    bool array;
    bool declaration;

    DeclarationVariable(char* _id, bool _array, bool _declaration);
};

#endif
