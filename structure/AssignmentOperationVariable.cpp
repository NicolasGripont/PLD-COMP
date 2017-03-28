#include "AssignmentOperationVariable.h"

AssignmentOperationVariable::AssignmentOperationVariable(ExpressionVariable* _exprVar, Expression* _expr, int _op)
	: AssignmentVariable(_exprVar,_expr), op(_op)
{

}

AssignmentOperationVariable::~AssignmentOperationVariable()
{}

string AssignmentOperationVariable::print() const
{
    string txt = AssignmentVariable::print();
#warning Ligne a completer !
    //txt.insert(txt.find_first_of('='), ); // On ajoute l'opérateur devant le signe '=' ('*' -> '*=')
    return txt;
}

