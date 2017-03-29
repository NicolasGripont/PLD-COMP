#ifndef _DECLARATION_H
#define _DECLARATION_H

#include "Printable.h"

enum DeclarationType
{
    GLOBAL_DECLARATION_VARIABLE,
    DECLARATION_FUNCTION
};

class Declaration : public Printable
{
private:
    DeclarationType type;
public:
    Declaration(DeclarationType _type);
    virtual ~Declaration();
    virtual string toString() const = 0;

    DeclarationType getType();
};

#endif
