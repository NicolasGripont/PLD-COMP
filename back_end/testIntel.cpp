#include "Intel.h"

/*
 * - How to use -
 * cd back_end/
 * make clean && make && g++ -o testIntel.out Intel.o testIntel.o && ./testIntel.out
 * ./intel.out
 */

int main(int argc, char* argv[])
{
    Intel* intel = new Intel();
    intel->test();
    intel->compile();
    delete intel;

    return 0;
}