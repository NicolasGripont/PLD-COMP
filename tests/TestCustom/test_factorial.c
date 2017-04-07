#include <ctest>

int32_t factorial(int32_t t)
{
	int32_t a = 0;
	if(1 < t)
	{
		a = t * factorial(t-1);
	}
	else
	{
		a = 1;
	}
	return a;
}

void main()
{
	int32_t b = 0;
	b = factorial(4);
	putchar(3 * b);
}
