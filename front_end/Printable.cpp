#include "Printable.h"

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
