.text
.global main

main:
	movl $'I', %edi
	callq putchar
	movl $'N', %edi
	callq putchar
	movl $'T', %edi
	callq putchar
	movl $'E', %edi
	callq putchar
	movl $'L', %edi
	callq putchar
	movl $'\n', %edi
	callq putchar

	retq
