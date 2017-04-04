/* ------------------ */
/* - Main principal - */
/* ------------------ */

#include "comp.tab.h"
#include "middle_end/Parser.h"
#include "back_end/Intel.h"

int main(int argc, char* argv[])
{
    std::cout << "-> Print du programme \n" << std::endl;
    /* Bison */
    Genesis* genesis = bison(argc, argv);

	if (genesis == nullptr)
	{
		return 1;
	}

    /* Conversion AST -> IR */
    Parser astToIRParser;
    astToIRParser.generateIR(genesis);

    std::cout << "\n-> Print de l'IR \n" << std::endl;
    std::cout << astToIRParser.getFunctionCFG().find("main")->second << std::endl;

	/* Backend Intel */
	Intel* intel = new Intel("intel", astToIRParser.getFunctionCFG());
	intel->parse();
	intel->compile();

	delete intel;

    if (genesis != nullptr)
    {
        delete genesis;
    }

    return 0;
}
