#ifndef GENESIS_H
#define GENESIS_H
#include <iostream>
#include <vector>
#include "declaration.h"

using namespace std;

class Genesis {
public:
	Genesis();
	~Genesis();
	string print() const;

	void addDeclaration(Declaration* declaration);
private:
	vector<Declaration*> declarations;
};

#endif
