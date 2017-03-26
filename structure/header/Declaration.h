#ifndef DECLARATION_H
#define DECLARATION_H

class Declaration
{
public:
    Declaration(Declaration * nextNode);
    ~Declaration();

private:
    Declaration * nextNode;
};

#endif // DECLARATION_H
