/* ------------------ */
/* - Main principal - */
/* ------------------ */

#include "comp.tab.h"
#include "middle_end/CFG.h"
#include "back_end/Intel.h"

/* Test */
#include "back_end/testIR.h"

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
    cfg->parseAST(genesis);

	if (genesis != nullptr)
	{
		delete genesis;
	}

	/* Backend Intel */
	Intel* intel = new Intel("intel");
	intel->parse(testIR1());
	intel->compile();

	delete intel;

    return 0;
}
