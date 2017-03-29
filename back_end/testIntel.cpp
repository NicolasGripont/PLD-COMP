#include "Intel.h"

/*
 * - How to use -
 * cd back_end/
 * make && g++ -o testIntel Intel.o testIntel.o && ./testIntel && ./intel
 *
 */

int main(int argc, char* argv[])
{
    Intel* intel = new Intel();
    intel->test();
    intel->compile();
    delete intel;

    return 0;
}