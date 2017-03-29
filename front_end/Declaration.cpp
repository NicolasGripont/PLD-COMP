#include "Declaration.h"

Declaration::Declaration(DeclarationType _type) : Printable(), type(_type)
{

}

Declaration::~Declaration()
{

}


DeclarationType Declaration::getType()
{
	return type;
}