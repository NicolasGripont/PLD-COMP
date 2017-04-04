.text
.global main

main:
	pushq %rbp
	movq %rsp, %rbp
	subq $32, %rsp
main_BB_0:
epilog_main:
	leave
	ret

