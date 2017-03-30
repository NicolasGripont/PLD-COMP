.text
.global main

main:
	movl $'I', %edi
	call putchar
	movl $'N', %edi
	call putchar
	movl $'T', %edi
	call putchar
	movl $'E', %edi
	call putchar
	movl $'L', %edi
	call putchar
	movl $'\n', %edi
	call putchar

	retq
