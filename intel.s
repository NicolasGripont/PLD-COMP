.text
.global main

main:
	pushq %rbp
	movq %rsp, %rbp
	subq $192, %rsp
main_BB_0:
//loadConstant
	movq $2, -16(%rbp)
//rwmemory
	movq -16(%rbp), %rax
	movq %rax, -8(%rbp)
//loadConstant
	movq $2, -32(%rbp)
//binaryOp
	movq -32(%rbp), %rax
	movq -8(%rbp), %rbx
	add %rbx, %rax
	movq %rax, -40(%rbp)
//rwmemory
	movq -40(%rbp), %rax
	movq %rax, -24(%rbp)
epilog_main:
	leave
	ret

