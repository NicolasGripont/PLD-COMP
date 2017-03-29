#include "Statement.h"

Statement::Statement(MultipleStatement* _multipleStatement)
    : Printable(), multipleStatement(_multipleStatement)
{

}

Statement::~Statement()
{
	if(multipleStatement != nullptr) 
	{
		delete multipleStatement;
	}
}

string Statement::toString() const
{
	return "{" + multipleStatement->toString() + "}";
}
