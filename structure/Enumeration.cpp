#include "Enumeration.h"

int sizeOfType(int type)
{
    if(type == TOKEN_CHAR)
        return 1;
    if(type == TOKEN_INT64)
        return 8;
    return 4;
}

bool isArrayType(int type)
{
    return (type == TOKEN_INT64_ARRAY || type == TOKEN_INT32_ARRAY || type == TOKEN_CHAR_ARRAY);
}
