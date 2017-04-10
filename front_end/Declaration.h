#ifndef _DECLARATION_H
#define _DECLARATION_H

#include "Printable.h"
#include "IRTranslatable.h"

enum DeclarationType
{
    GLOBAL_DECLARATION_VARIABLE,
    DECLARATION_FUNCTION
};

class Declaration : public Printable, public IRTranslatable
{
public:
    Declaration(DeclarationType _type);
    virtual ~Declaration();

    DeclarationType getType();

private:
    DeclarationType type;
};

#endif
