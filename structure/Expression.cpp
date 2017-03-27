#include "Expression.h"


Expression::Expression():Printer(),type(EXPRESSION_TYPE_UNDEFINED)
{

}

int Expression::getType()
{
    return type;
}

void Expression::setType(int _type)
{
    type = _type;
}

string Expression::print() const
{
	return "Expression";
}
