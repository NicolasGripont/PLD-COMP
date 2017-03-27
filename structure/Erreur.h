// Struct qui n'est pas utilisee dans la structure de donnees
// mais qui sert a la detection des Erreur
struct VariableContainer
{
	char* name;
	int type;

	VariableContainer(char* _name, int _type):
	name(_name),type(_type){};
};

struct FunctionContainer
{
    char* name;
	int type;
    // Si vrai : Declaration, si faux : initialisation
    bool declaration;

	FunctionContainer(char* _name, int _type, bool _declaration):
	name(_name),type(_type),declaration(_declaration){};
};