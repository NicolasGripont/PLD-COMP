#include "stdint.h"
#include "stdio.h"

void print_alphabet_recurcive(char c);

void print_alphabet_while()
{
    char c = 'a';
    char end = 'z' + 1;

    while (c != end)
    {
        putchar(c);
        c++;
    }
    putchar('\n');
}

int64_t main() 
{
    print_alphabet_while();
	print_alphabet_recurcive('a');
	return 0;
}


void print_alphabet_recurcive(char c)
{
	putchar(c);
	if(c == 'z') {
		putchar('\n');
    } else {
        print_alphabet_recurcive(++c);
    }
}
