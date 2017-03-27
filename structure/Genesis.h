#ifndef _GENESIS_H
#define _GENESIS_H

#include <vector>

#include "Declaration.h"
#include "Printer.h"

class Genesis : public Printer
{
public:
    Genesis();
	virtual string print() const;
    void addDeclaration(Declaration* declaration);
    int countDeclaration();

    Declaration*& operator[] (int i);

private:
    std::vector<Declaration*> declarations;
};

#endif
