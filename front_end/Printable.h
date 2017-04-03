#ifndef _PRINTABLE_H
#define _PRINTABLE_H

#include <iostream>

#include "Printable.h"

class Printable
{
public:
    Printable() = default;
    virtual ~Printable() = default;
    virtual std::string toString() const = 0;
	friend std::ostream& operator<<(std::ostream& os, const Printable& dt);
	friend std::ostream& operator<<(std::ostream& os, const Printable* dt);  
};

#endif
