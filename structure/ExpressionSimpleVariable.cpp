#include "ExpressionSimpleVariable.h"

ExpressionSimpleVariable::ExpressionSimpleVariable(char* _id)
    : ExpressionVariable(), id(_id)
{

}

string ExpressionSimpleVariable::print() {
	return "ExpressionSimpleVariable";
}