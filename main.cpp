/* ------------------ */
/* - Main principal - */
/* ------------------ */

#include "comp.tab.h"
#include "middle_end/Parser.h"
#include "back_end/x64.h"
#include "back_end/Java.h"

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

	/* Backend x64 */
	x64* intel = new x64("x64", astToIRParser.getFunctionCFG());
	intel->parse();
	intel->compile();

    delete intel;

    /* Backend Java */
    Java* java = new Java("java", astToIRParser.getFunctionCFG());
    java->parse();
    java->compile();

	delete java;

    if (genesis != nullptr)
    {
        delete genesis;
    }

    return 0;
}
