#ifndef _GENESIS_H
#define _GENESIS_H

#include <vector>

#include "Declaration.h"
#include "Printable.h"

class Genesis : public Printable, public IRTranslatable
{
public:
    Genesis();
    virtual ~Genesis();

    std::string toString() const;
    void buildIR(CFG * cfg) const;

    void addDeclaration(Declaration* declaration);
    int countDeclaration();

    Declaration*& operator[] (int i);

private:
    std::vector<Declaration*> declarations;
};

#endif
