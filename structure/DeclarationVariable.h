#ifndef _DECLARATIONVARIABLE_H
#define _DECLARATIONVARIABLE_H

class DeclarationVariable
{
public:
    DeclarationVariable(char* _id);
    char* getId();

protected:
    char* id;
};

#endif
