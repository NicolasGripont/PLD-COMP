#include <ctest>

int32_t factorial(int32_t t)
{
	if(t > 1)
	{
		return t * factorial(t-1);
	}
	return 1;
}

void main()
{
	factorial(10);
}
