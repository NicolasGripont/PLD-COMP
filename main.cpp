/* ------------------ */
/* - Main principal - */
/* ------------------ */

#include "comp.tab.h"

int main(int argc, char* argv[])
{
	int retourBison = -1;

	/* Bison */
	retourBison = bison(argc, argv);
	if (retourBison != 0)
	{
		return retourBison;
	}
}