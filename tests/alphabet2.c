void print_alphabet(char c)
{
	if (c == 'Z')
	{
		putchar('\n');
	}
	else
	{
		putchar(c);
		print_alphabet(c + 1);
	}
}

void main()
{
	print_alphabet('A');
}
