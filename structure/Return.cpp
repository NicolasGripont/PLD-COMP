#include "Return.h"

Return::Return(Expression* _expr)
    : Printer(), expr(_expr)
{

}

string Return::print() const
{
	return "Return";
}