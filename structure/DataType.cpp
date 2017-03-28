#include "DataType.h"

int INT32_T = 0;
int INT64_T = 0;
int CHAR_T = 0;

void defineTypes(int int32, int int64, int charType)
{
    INT32_T = int32;
    INT64_T = int64;
    CHAR_T = charType;
}

int sizeOfType(int type)
{
    if(type == CHAR_T)
        return 1;
    if(type == INT64_T)
        return 8;
    return 4;
}

bool isArrayType(int type)
{
    return (type == INT64_ARRAY || type == INT32_ARRAY || type == CHAR_ARRAY);
}
