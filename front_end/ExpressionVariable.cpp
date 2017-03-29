#include "ExpressionVariable.h"

ExpressionVariable::ExpressionVariable(int _type)
:Expression()
{
    setType(_type);
    setExpressionType(EXPRESSION_VARIABLE);
}

ExpressionVariable::~ExpressionVariable()
{

}
