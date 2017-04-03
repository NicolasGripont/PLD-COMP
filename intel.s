.text
.global main

main_prologue:
	pushq %rbp
	movq %rsp, %rbp
	subq $32, %rsp
main:
main_epilog:
	leave
	ret
