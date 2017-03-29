#ifndef _DECLARATIONARRAYVARIABLE_H
#define _DECLARATIONARRAYVARIABLE_H

#include "DeclarationVariable.h"

class DeclarationArrayVariable : public DeclarationVariable 
{
public:
	DeclarationArrayVariable(char* _id, int _size);
	virtual ~DeclarationArrayVariable();
	virtual string toString() const;
	
private:
	int size;
};


#endif