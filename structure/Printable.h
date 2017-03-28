#ifndef _PRINTABLE_H
#define _PRINTABLE_H

#include <iostream>

#include "Printable.h"

using namespace std;

class Printable
{
public:
	Printable();
	virtual ~Printable();
	virtual string toString() const = 0;
	friend ostream& operator<<(ostream& os, const Printable& dt);
	friend ostream& operator<<(ostream& os, const Printable* dt);  
};

#endif