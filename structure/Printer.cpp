#include "Printer.h"

Printer::Printer()
{

}

ostream& operator<<(ostream& os, const Printer& dt)  
{  
    os << dt.print();  
    return os;  
}  