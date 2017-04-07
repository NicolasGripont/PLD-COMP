#include "stdint.h"
#include "stdio.h"

int64_t factoriel_while(int64_t number);
void print_recursive1(int64_t number);
void print_recursive2(int64_t number);
void print(int64_t); 

int64_t factoriel_recurcive(int64_t number)
{
    int64_t result = 1;
    int64_t i = 2;

    if(number < 0) //impossible
    {
        result = 0;
    } else {
        if(number < 2) {
            result = 1;
        } else {
            result = number * factoriel_recurcive(number - 1);
        }
    }


    return result;
}


int64_t main () 
{
	int64_t factoriel;
    int64_t i = 0;
	
    while(i < 6)
    {
        factoriel = factoriel_while(i);
        // print(factoriel1);
//        print_recursive1(factoriel);
        i++;
    }

    i = 0;
    while(i < 6)
    {
        factoriel = factoriel_recurcive(i);
//        print(factoriel);
        i++;
    }
	putchar('T');
	putchar('O');
	putchar('U');
	putchar('C');
	putchar('H');
	putchar('D');
	putchar('O');
	putchar('W');
	putchar('N');
    putchar(' ');
    putchar('!');
	putchar('\n');

	return 0;
}


int64_t factoriel_while(int64_t number)
{
    int64_t result = 1;
    int64_t i = 2;

    if(number < 0) //impossible
    {
        result = 0;
    }

    while(i <= number)
    {
        result *= i;
        i++;
    }

    return result;
}

void print(int64_t result)
{
    char sign = '+';
    int64_t reverse = 0;
    int64_t i = 1;
    char base = '0';
    char currentChar;
    int64_t currentDigit;

    if(result < 0)
    {
        result *= -1;
        putchar('-');
    }

    while((result / i) > 10)
    {
        i *= 10;
    }

    while (i > 0)
    {
        currentDigit = result / i;
        currentChar = base + currentDigit;
        putchar(currentChar);
        result %= i;
        i /= 10;
    }

    putchar('\n');
}

void print_recursive1(int64_t number)
{
    if(number < 0)
    {
        number *= -1;
        putchar('-');
    }
    if(number == 0) {
        putchar('0');
    } else {
        print_recursive2(number);
    }

    putchar('\n');
}


void print_recursive2(int64_t number)
{
    if(number != 0) {
        print_recursive2(number/10);
        putchar('0'+number%10);
    }
}
