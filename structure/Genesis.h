#ifndef _GENESIS_H
#define _GENESIS_h

#include <vector>

#include "Declaration.h"

class Genesis
{
public:
	Genesis();
	
	void addDeclaration(Declaration* declaration);
	int countDeclaration();
	Declaration*& operator[] (int i);
private:
	std::vector<Declaration*> declarations;
};

#endif
