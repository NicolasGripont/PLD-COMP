#include "ExpressionArrayVariable.h"

ExpressionArrayVariable::ExpressionArrayVariable(char* _id, Expression* _expr)
	:ExpressionVariable(), id(_id), expr(_expr)
{

}

string ExpressionArrayVariable::print() {
	return "ExpressionArrayVariable";
}