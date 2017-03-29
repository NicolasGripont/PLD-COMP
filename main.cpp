/* ------------------ */
/* - Main principal - */
/* ------------------ */

#include "comp.tab.h"
#include "middle_end/CFG.h"

int main(int argc, char* argv[])
{
    /* Bison */
    Genesis* genesis = bison(argc, argv);

	if (genesis == nullptr)
	{
		return 1;
	}

    /* Conversion AST -> IR */
    CFG* cfg = new CFG();
    cfg->parseGenesis(genesis);

	if (genesis != nullptr)
	{
		delete genesis;
	}
	
    
    return 0;
}
