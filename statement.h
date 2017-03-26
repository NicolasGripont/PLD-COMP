#ifndef STATEMENT_H
#define STATEMENT_H
#include <iostream>

using namespace std;

class Statement {
public:
	Statement();
	~Statement();
	virtual string print() const = 0;
};
#endif
