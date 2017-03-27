#include "FunctionCallExpression.h"

FunctionCallExpression::FunctionCallExpression(char* _id, Expression* _expr)
	: Expression(), id(_id), expr(_expr)
{

}

string FunctionCallExpression::print() {
	return "FunctionCallExpression";
}