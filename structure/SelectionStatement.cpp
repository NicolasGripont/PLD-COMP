#include "SelectionStatement.h"

SelectionStatement::SelectionStatement(Expression* _expr, Statement* _stat, Statement* _elseStat)
    : SimpleStatement(SELECTION_STATEMENT), expr(_expr), stat(_stat), elseStat(_elseStat)
{

}

string SelectionStatement::print() const
{
	return "SelectionStatement";
}
