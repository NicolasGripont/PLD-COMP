/* ------------------ */
/* - Main principal - */
/* ------------------ */

#include "comp.tab.h"
#include "middle_end/Parser.h"
#include "back_end/X64.h"
#include "back_end/Java.h"

int main(int argc, char* argv[])
{
    std::cout << "-> Print du programme\n" << std::endl;
    /* Bison */
    Genesis* genesis = bison(argc, argv);

	if (genesis == nullptr)
	{
		return 1;
	}

    /* Conversion AST -> IR */
    Parser astToIRParser;
    astToIRParser.generateIR(genesis);

    std::cout << "\n-> Print de l'IR\n" << std::endl;
    std::cout << "NB CFG : " << astToIRParser.getFunctionCFG().size() << std::endl;
    for(auto pair : astToIRParser.getFunctionCFG())
    {
        std::cout << pair.second << std::endl;
    }

    std::cout << "\n-> Assemblage\n" << std::endl;
	/* Backend x64 */
    std::cout << "   - x64: starting..." << std::endl;
	X64* x64 = new X64("x64", astToIRParser.getFunctionCFG());
	x64->parse();
	x64->compile();

    delete x64;
    std::cout << "   - x64:         ...ending." << std::endl;

    /* Backend Java */
    std::cout << "   - Java: starting..." << std::endl;
    Java* java = new Java("java", astToIRParser.getFunctionCFG());
    java->parse();
    java->compile();

	delete java;
    std::cout << "   - Java:         ...ending." << std::endl;

    if (genesis != nullptr)
    {
        delete genesis;
    }

    return 0;
}
