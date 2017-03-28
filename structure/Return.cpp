#include "Return.h"

Return::Return(Expression* _expr)
    : Printable(), expr(_expr)
{

}

Return::~Return()
{
    delete expr;
}

string Return::toString() const
{
	return "Return";
}
