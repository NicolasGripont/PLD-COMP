#ifndef _DECLARATIONVARIABLE_H
#define _DECLARATIONVARIABLE_H

#include "Printer.h"

class DeclarationVariable : public Printer
{
public:
 
    DeclarationVariable(char* _id, bool _array);
    char* getId();	bool isArray();
	virtual string print() const;
protected:
    char* id;
    bool array;
};

#endif
