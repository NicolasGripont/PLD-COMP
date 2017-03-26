#ifndef ARGUMENT_H
#define ARGUMENT_H
#include <iostream>
#include "type.h"
using namespace std;

class Argument {
public:
	Argument(TYPE type, string name = "", bool _isArray = false);
	~Argument();
	virtual string print() const;
private:
	TYPE type;
	string name;
	bool isArray;
};
#endif
