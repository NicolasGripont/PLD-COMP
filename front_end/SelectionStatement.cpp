#include "SelectionStatement.h"

SelectionStatement::SelectionStatement(Expression* _expr, Statement* _stat, Statement* _elseStat)
    : SimpleStatement(SELECTION_STATEMENT), expr(_expr), stat(_stat), elseStat(_elseStat)
{

}

SelectionStatement::~SelectionStatement()
{
    delete expr;
    delete stat;
    delete elseStat;
}

string SelectionStatement::toString() const
{
	string txt = "";
	if(expr != nullptr && stat != nullptr && elseStat != nullptr) 
	{
		txt += string("if(") + expr->toString() + string(")") + stat->toString() + string(" else ") + elseStat->toString();
	} 
	else if (expr != nullptr && stat != nullptr && elseStat == nullptr)
	{
		txt += string("if(") + expr->toString() + string(")") + stat->toString();
	}
	else if (expr != nullptr && stat == nullptr && elseStat == nullptr)
	{
		txt += string("if(") + expr->toString() + string("){}");
	} 
	else
	{
		txt = "ERROR_SelectionStatement";
	}
	return txt;
}
