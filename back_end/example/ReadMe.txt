Look at main.s: this is the kind of file your project must produce.

And to compile it, run
	as -o main.o main.s
	gcc main.o 

The first line calls the GNU assembler and produces an object file main.o
The second line wraps up this main.o with all what the OS needs
 (allocate a stack, etc)

It also links with the whole glibc, so we may use putchar
