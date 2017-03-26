#ifndef MULTIPLEARGUMENT_H
#define MULTIPLEARGUMENT_H

#include "Argument.h"

#include <vector>

using namespace std;

class MultipleArgument
{
public:
    MultipleArgument();
    ~MultipleArgument();

    void addArgument(Argument *arg);
private:
    vector<Argument*> listArguments;
};

#endif // MULTIPLEARGUMENT_H
