#include "Type.h"

Type::Type(int _type) : Printer(), type(_type)
{

}

Type::~Type()
{

}

int Type::getType()
{
    return type;
}

string Type::print() const
{
	string typeStr = "";
	// switch(type)  
 //      {  
 //        case TOKEN_VOID:  
 //            typeStr = "void";  
 //            break;  
 //        case TOKEN_CHAR:  
 //            typeStr = "char";  
 //            break; 
 //        case TOKEN_INT32:  
 //            typeStr = "int32_t";  
 //            break;  
 //        case TOKEN_INT64:  
 //            typeStr = "int64_t";  
 //            break;  
 //        default:  
 //            typeStr = "ERROR_Type";  
 //      }  
	return typeStr;
}
