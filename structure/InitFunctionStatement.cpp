#include "InitFunctionStatement.h"

InitFunctionStatement::InitFunctionStatement(MultipleStatement* _multipleStatement)
    : DeclarationFunctionStatement(false), multipleStatement(_multipleStatement)
{

}

string InitFunctionStatement::print() {
	return "InitFunctionStatement";
}