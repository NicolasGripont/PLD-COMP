#include "Statement.h"

 Statement::Statement(MultipleStatement* _multipleStatement)
    : Printer(), multipleStatement(_multipleStatement)
{

}

Statement::~Statement()
{

}

string Statement::print() const
{
	return "Statement";
}