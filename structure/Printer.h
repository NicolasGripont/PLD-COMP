#ifndef _PRINTER_H
#define _PRINTER_H

#include <iostream>

#include "Printer.h"

using namespace std;

class Printer
{
public:
	Printer();
	virtual ~Printer();
	virtual string print() const = 0;
	friend ostream& operator<<(ostream& os, const Printer& dt);  
};

#endif