#include "Enumeration.h"
#include "../comp.tab.h"

int sizeOfType(int type)
{
    if(type == CHAR)
        return 1;
    if(type == INT64)
        return 8;
    return 4;
}

bool isArrayType(int type)
{
	return (type == INT64_ARRAY || type == INT32_ARRAY || type == CHAR_ARRAY);
}
