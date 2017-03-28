#include "Statement.h"

 Statement::Statement(MultipleStatement* _multipleStatement)
    : Printable(), multipleStatement(_multipleStatement)
{

}

Statement::~Statement()
{
    delete multipleStatement;
}

string Statement::toString() const
{
	#warning check where should '{}' be put
	return string("{") + multipleStatement->toString() + string("}");
}
