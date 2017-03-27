#include "ReturnStatement.h"

ReturnStatement::ReturnStatement(Return* _ret)
    : SimpleStatement(RETURN_STATEMENT), ret(_ret)
{

}
