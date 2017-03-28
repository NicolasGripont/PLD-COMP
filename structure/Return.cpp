#include "Return.h"

Return::Return(Expression* _expr)
    : Printer(), expr(_expr)
{

}

Return::~Return()
{

}

string Return::print() const
{
	return "Return";
}