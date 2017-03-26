#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <iostream>

using namespace std;

class Expression
{
public:
    Expression();
    
    virtual ~Expression();
    virtual Expression print() const;
};

#endif
