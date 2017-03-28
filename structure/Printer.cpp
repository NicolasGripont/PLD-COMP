#include "Printer.h"

Printer::Printer()
{

}

Printer::~Printer()
{

}

ostream& operator<<(ostream& os, const Printer& dt)  
{  
    os << dt.print();  
    return os;  
}  