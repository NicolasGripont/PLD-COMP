#ifndef _DECLARATION_H
#define _DECLARATION_H

#include "Printable.h"
#include "IRTranslatable.h"

enum DeclarationType
{
    GLOBAL_DECLARATION_VARIABLE,
    DECLARATION_FUNCTION
};

class Declaration : public Printable, IRTranslatable
{
public:
    Declaration(DeclarationType _type);
    virtual ~Declaration();

    void buildIR(CFG * cfg) const;

    DeclarationType getType();

private:
    DeclarationType type;
};

#endif
