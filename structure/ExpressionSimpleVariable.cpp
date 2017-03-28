#include "ExpressionSimpleVariable.h"


ExpressionSimpleVariable::ExpressionSimpleVariable(char* _id, int _type)
    : ExpressionVariable(_type),id(_id)
{


}

ExpressionSimpleVariable::~ExpressionSimpleVariable()
{

}

string ExpressionSimpleVariable::print() const
{
	return "ExpressionSimpleVariable";
}