#include "SelectionStatement.h"

SelectionStatement::SelectionStatement(Expression* _expr, Statement* _stat, Statement* _elseStat)
    : SimpleStatement(SELECTION_STATEMENT), expr(_expr), stat(_stat), elseStat(_elseStat)
{

}

SelectionStatement::~SelectionStatement()
{
	if(expr != nullptr) 
	{
		delete expr;
	} 
	if(stat != nullptr) 
	{
		delete stat;
	} 
	if(elseStat != nullptr) 
	{
		delete elseStat;
	} 
}

std::string SelectionStatement::toString() const
{
	std::string txt = "";
	if(expr != nullptr && stat != nullptr && elseStat != nullptr) 
	{
		txt += "if(" + expr->toString() + ")" + stat->toString() + " else " + elseStat->toString();
	} 
	else if (expr != nullptr && stat != nullptr && elseStat == nullptr)
	{
		txt += "if(" + expr->toString() + ")" + stat->toString();
	}
	else if (expr != nullptr && stat == nullptr && elseStat == nullptr)
	{
		txt += "if(" + expr->toString() + "){}";
	} 
	else
	{
		txt = "ERROR_SelectionStatement";
	}
    return txt;
}

void SelectionStatement::buildIR(CFG *cfg) const
{

}
