#ifndef _DECLARATIONVARIABLE_H
#define _DECLARATIONVARIABLE_H

#include "Printable.h"

class DeclarationVariable : public Printable
{
public:
 
    DeclarationVariable(char* _id, bool _array);
    virtual ~DeclarationVariable(); 
    char* getId();	bool isArray();
	virtual string toString() const;
protected:
    char* id;
    bool array;
};

#endif
