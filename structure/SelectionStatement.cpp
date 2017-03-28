#include "SelectionStatement.h"

SelectionStatement::SelectionStatement(Expression* _expr, Statement* _stat, Statement* _elseStat)
    : SimpleStatement(SELECTION_STATEMENT), expr(_expr), stat(_stat), elseStat(_elseStat)
{

}

SelectionStatement::~SelectionStatement()
{

}

string SelectionStatement::toString() const
{
	return "SelectionStatement";
}
