#include "Return.h"

Return::Return(Expression* _expr)
    : Printable(), expr(_expr)
{

}

Return::~Return()
{

}

string Return::toString() const
{
	return "Return";
}