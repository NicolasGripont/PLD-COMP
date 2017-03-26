#ifndef _GENESIS_H
#define _GENESIS_H

#include "Declaration.h"

#include <vector>

using namespace std;

class Genesis
{
public:

    enum class Type
    {
        VOID,
        INT32_T,
        INT64_T,
        CHAR
    };

    Genesis();
    ~Genesis();

    void addDeclaration(const Declaration * dec);

private:

    vector<Declaration*> declarations;
};

#endif // _GENESIS_H
