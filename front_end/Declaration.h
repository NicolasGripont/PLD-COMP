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
public:
    Declaration(DeclarationType _type);
    virtual ~Declaration();
    virtual std::string toString() const = 0;

    DeclarationType getType();

private:
    DeclarationType type;
};

#endif
