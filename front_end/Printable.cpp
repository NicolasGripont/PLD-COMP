#include "Printable.h"

Printable::Printable()
{

}

Printable::~Printable()
{

}

ostream& operator<<(ostream& os, const Printable& dt)  
{  
    os << dt.toString();  
    return os;  
}  

ostream& operator<<(ostream& os, const Printable* dt)  
{  
    os << dt->toString();  
    return os;  
}  