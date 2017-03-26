#ifndef MULTIPLEARGUMENT_H
#define MULTIPLEARGUMENT_H
#include <iostream>
#include <vector>
#include "argument.h"

using namespace std;

class MultipleArgument {
public:
	MultipleArgument();
	~MultipleArgument();
	void addArgument(Argument *);
	virtual string print() const;
private:
	vector<Argument *> arguments;
};
#endif
