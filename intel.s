.text
.global main

main:
	pushq %rbp
	movq %rsp, %rbp
	subq $192, %rsp
main_BB_0:
epilog_main:
	leave
	ret

poutre:
	pushq %rbp
	movq %rsp, %rbp
	subq $192, %rsp
poutre_BB_0:
//loadConstant
	movq $18, -16(%rbp)
//call
	movl -16(%rbp), %edi
	call putchar
epilog_poutre:
	leave
	ret

poutre2:
	pushq %rbp
	movq %rsp, %rbp
	subq $192, %rsp
poutre2_BB_0:
//loadConstant
	movq $18, -16(%rbp)
//call
	movl -16(%rbp), %edi
	call putchar
epilog_poutre2:
	leave
	ret

