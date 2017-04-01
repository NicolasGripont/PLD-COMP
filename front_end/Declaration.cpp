#include "Declaration.h"

Declaration::Declaration(DeclarationType _type)
	: Printable(), type(_type)
{

}

Declaration::~Declaration()
{

}

void Declaration::buildIR(CFG *cfg) const
{

}

DeclarationType Declaration::getType()
{
	return type;
}
