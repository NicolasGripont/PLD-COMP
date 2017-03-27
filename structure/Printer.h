#ifndef _PRINTER_H
#define _PRINTER_H

#include <iostream>

#include "Printer.h"

using namespace std;

class Printer
{
public:
	Printer();

	virtual string print() = 0;
};

#endif