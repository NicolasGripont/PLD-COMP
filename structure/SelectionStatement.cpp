#include "SelectionStatement.h"

SelectionStatement::SelectionStatement(Expression* _expr, Statement* _stat, Statement* _elseStat)
    : SimpleStatement(), expr(_expr), stat(_stat), elseStat(_elseStat)
{

}

string SelectionStatement::print() {
	return "SelectionStatement";
}