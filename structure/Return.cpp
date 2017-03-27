#include "Return.h"

Return::Return(Expression* _expr)
    : Printer(), expr(_expr)
{

}

string Return::print() {
	return "Return";
}