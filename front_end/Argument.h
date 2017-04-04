#ifndef _ARGUMENT_H
#define _ARGUMENT_H

#include "Type.h"
#include "Printable.h"
#include "IRTranslatable.h"

class Argument : public Printable, public IRTranslatable
{
public:
    Argument(Type* _type, char* _id = nullptr, bool _array = false);
    virtual ~Argument();

    virtual std::string toString() const;
    virtual void buildIR(CFG * cfg) const;

    Type* getType();
    char* getName();
    bool isArray();

private:
    static std::string unnamedBase;
    static int unnamedCount;

    Type* type;
    char* id;
    bool array;
};

#endif
