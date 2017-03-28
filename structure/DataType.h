#ifndef _DATA_TYPE_H
#define _DATA_TYPE_H

const int EXPRESSION_TYPE_UNDEFINED = -1;
const int EXPRESSION_TYPE_CONFLICT = -2;
const int CHAR_ARRAY = -3;
const int INT32_ARRAY = -4;
const int INT64_ARRAY = -5;
extern int INT32_T;
extern int INT64_T;
extern int CHAR_T;

// Donner un alias pour IN32, INT64, et CHAR, accessible de partout
void defineTypes(int int32, int int64, int charType);

int sizeOfType(int type);

bool isArrayType(int type);

#endif
