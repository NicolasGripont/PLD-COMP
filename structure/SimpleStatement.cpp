#include "SimpleStatement.h"

SimpleStatement::SimpleStatement(SimpleStatementType _type):type(_type)
{

}

SimpleStatementType SimpleStatement::getType()
{
    return type;
}
