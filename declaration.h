#ifndef DECLARATION_H
#define DECLARATION_H
#include <iostream>

using namespace std;

class Declaration
{
public:
    Declaration();
    virtual ~Declaration();
    virtual string print() const = 0;
};

#endif
