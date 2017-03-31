#include "Type.h"
#include "../comp.tab.h"

Type::Type(int _type)
    : Printable(), type(_type)
{

}

Type::~Type()
{

}

int Type::getType()
{
    return type;
}

std::string Type::toString() const
{
	std::string typeStr = "";
	switch(type)  
    {  
        case VOID:  
            typeStr += "void";  
            break;  
        case CHAR:  
            typeStr += "char";  
            break; 
        case INT32:  
            typeStr += "int32_t";  
            break;  
        case INT64:  
            typeStr += "int64_t";  
            break;  
        default:  
            typeStr += "ERROR_Type";  
    }  
	return typeStr;
}
