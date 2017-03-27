#include "ForLoop.h"

ForLoop::ForLoop(LoopExpression* _expr1, LoopExpression* _expr2, LoopExpression* _expr3, Statement* _statement)
    : expr1(_expr1), expr2(_expr2), expr3(_expr3), IterationStatement(_statement)
{

}