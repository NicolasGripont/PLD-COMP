#include "ExpressionInteger.h"

ExpressionInteger::ExpressionInteger(int _value)
	: Expression(), value(_value)
{

}

string ExpressionInteger::print() {
	return "ExpressionInteger";
}