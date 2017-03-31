#include "Printable.h"

Printable::Printable()
{

}

Printable::~Printable()
{

}

std::ostream& operator<<(std::ostream& os, const Printable& dt)  
{  
    os << dt.toString();  
    return os;  
}  

std::ostream& operator<<(std::ostream& os, const Printable* dt)  
{  
    os << dt->toString();  
    return os;  
}  