#ifndef _ARGUMENT_H
#define _ARGUMENT_H

#include "Type.h"
#include "Printable.h"
#include "IRTranslatable.h"

class Argument : public Printable, IRTranslatable
{
public:
    Argument(Type* _type, char* _id = nullptr, bool _array = false);
    virtual ~Argument();

    std::string toString() const;
    void buildIR(CFG * cfg) const;

    Type* getType();
    char* getName();
    bool isArray();

private:
    Type* type;
    char* id;
    bool array;
};

#endif
