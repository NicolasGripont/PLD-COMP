#ifndef _GENESIS_H
#define _GENESIS_H

#include <vector>

#include "Declaration.h"
#include "Printable.h"

class Genesis : public Printable
{
public:
    Genesis();
    virtual ~Genesis();
	virtual string toString() const;
    void addDeclaration(Declaration* declaration);
    int countDeclaration();

    Declaration*& operator[] (int i);

private:
    std::vector<Declaration*> declarations;
};

#endif
