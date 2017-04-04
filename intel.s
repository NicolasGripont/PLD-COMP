.text
.global main

factoriel_recurcive:
	pushq %rbp
	movq %rsp, %rbp
	subq $192, %rsp
factoriel_recurcive_BB_0:
//loadConstant
	movq $1, -16(%rbp)
//rwmemory
	movq -16(%rbp), %rax
	movq %rax, -8(%rbp)
//loadConstant
	movq $2, -32(%rbp)
//rwmemory
	movq -32(%rbp), %rax
	movq %rax, -24(%rbp)
epilog_factoriel_recurcive:
	leave
	ret

factoriel_while:
	pushq %rbp
	movq %rsp, %rbp
	subq $192, %rsp
epilog_factoriel_while:
	leave
	ret

main:
	pushq %rbp
	movq %rsp, %rbp
	subq $192, %rsp
main_BB_0:
//loadConstant
	movq $0, -24(%rbp)
//rwmemory
	movq -24(%rbp), %rax
	movq %rax, -16(%rbp)
//loadConstant
	movq $0, -32(%rbp)
//rwmemory
	movq -32(%rbp), %rax
	movq %rax, -16(%rbp)
//loadConstant
	movq $84, -48(%rbp)
//call
	movl -48(%rbp), %edi
	call putchar
//loadConstant
	movq $79, -64(%rbp)
//call
	movl -64(%rbp), %edi
	call putchar
//loadConstant
	movq $85, -80(%rbp)
//call
	movl -80(%rbp), %edi
	call putchar
//loadConstant
	movq $67, -96(%rbp)
//call
	movl -96(%rbp), %edi
	call putchar
//loadConstant
	movq $72, -112(%rbp)
//call
	movl -112(%rbp), %edi
	call putchar
//loadConstant
	movq $68, -128(%rbp)
//call
	movl -128(%rbp), %edi
	call putchar
//loadConstant
	movq $79, -144(%rbp)
//call
	movl -144(%rbp), %edi
	call putchar
//loadConstant
	movq $87, -160(%rbp)
//call
	movl -160(%rbp), %edi
	call putchar
//loadConstant
	movq $78, -176(%rbp)
//call
	movl -176(%rbp), %edi
	call putchar
//loadConstant
	movq $32, -192(%rbp)
//call
	movl -192(%rbp), %edi
	call putchar
//loadConstant
	movq $33, -208(%rbp)
//call
	movl -208(%rbp), %edi
	call putchar
//loadConstant
	movq $10, -224(%rbp)
//call
	movl -224(%rbp), %edi
	call putchar
epilog_main:
	leave
	ret

print:
	pushq %rbp
	movq %rsp, %rbp
	subq $192, %rsp
epilog_print:
	leave
	ret

