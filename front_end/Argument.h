#ifndef _ARGUMENT_H
#define _ARGUMENT_H

#include "Type.h"
#include "Printable.h"

class Argument : public Printable
{
public:
    Argument(Type* _type, char* _id = nullptr, bool _array = false);
    virtual ~Argument();
    virtual std::string toString() const;
    Type* getType();
    char* getName();
    bool isArray();

private:
    Type* type;
    char* id;
    bool array;
};

#endif
