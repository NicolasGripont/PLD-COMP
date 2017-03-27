#include "Statement.h"

 Statement::Statement(MultipleStatement* _multipleStatement)
    : Printer(), multipleStatement(_multipleStatement)
{

}

string Statement::print() const
{
	return "Statement";
}