#include "Expression.h"


Expression::Expression():Printer(),type(EXPRESSION_TYPE_UNDEFINED)
{

}

Expression::~Expression()
{

}

string Expression::print() const
{
	return "Expression";
}


int Expression::getType()
{
    return type;
}

void Expression::setType(int _type)
{
    type = _type;
}


