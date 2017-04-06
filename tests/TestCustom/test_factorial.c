#include <ctest>

int32_t factorial(int32_t n)
{
	if(n > 1)
	{
		return n * factorial(n-1);
	}
	return 1;
}

void main()
{
	factorial(5);
}