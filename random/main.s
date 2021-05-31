	.file	"main.c"
	.text
	.globl	randomselected
	.bss
	.type	randomselected, @object
	.size	randomselected, 1
randomselected:
	.zero	1
	.globl	num
	.align 4
	.type	num, @object
	.size	num, 4
num:
	.zero	4
	.text
	.globl	Random
	.type	Random, @function
Random:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	call	rand@PLT
	movl	-8(%rbp), %edx
	addl	$1, %edx
	movl	%edx, %ecx
	subl	-4(%rbp), %ecx
	cltd
	idivl	%ecx
	movl	-4(%rbp), %eax
	addl	%eax, %eax
	addl	%edx, %eax
	movl	%eax, num(%rip)
	movl	num(%rip), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	Random, .-Random
	.section	.rodata
.LC0:
	.string	"The Number Was %d"
	.text
	.globl	sig_handler
	.type	sig_handler, @function
sig_handler:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movzbl	randomselected(%rip), %eax
	testb	%al, %al
	je	.L4
	movl	num(%rip), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
.L4:
	movl	$130, %edi
	call	exit@PLT
	.cfi_endproc
.LFE7:
	.size	sig_handler, .-sig_handler
	.section	.rodata
.LC1:
	.string	"Lowest Number: "
.LC2:
	.string	"%d"
.LC3:
	.string	"Biggest Number: "
.LC4:
	.string	"w"
.LC5:
	.string	"Type an integer"
.LC6:
	.string	"Guess:"
.LC7:
	.string	"Correct\nit was %d\n"
.LC8:
	.string	"Your guess is too high"
.LC9:
	.string	"Your guess is too low"
.LC10:
	.string	"please type an integer"
	.text
	.globl	main
	.type	main, @function
main:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	sig_handler(%rip), %rax
	movq	%rax, %rsi
	movl	$2, %edi
	call	signal@PLT
	movl	$0, -16(%rbp)
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-28(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	cmpl	$1, %eax
	jne	.L6
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-24(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	cmpl	$1, %eax
	jne	.L7
	movl	-28(%rbp), %edx
	movl	-24(%rbp), %eax
	cmpl	%eax, %edx
	jle	.L8
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$1, %edi
	call	exit@PLT
.L7:
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$1, %edi
	call	exit@PLT
.L6:
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$1, %edi
	call	exit@PLT
.L8:
	movb	$1, randomselected(%rip)
	movl	$0, %edi
	call	time@PLT
	movl	%eax, %edi
	call	srand@PLT
	movl	-24(%rbp), %edx
	movl	-28(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	Random
	movl	%eax, -12(%rbp)
.L15:
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	cmpl	$1, %eax
	jne	.L9
	movl	-20(%rbp), %eax
	cmpl	%eax, -12(%rbp)
	jne	.L10
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L17
	jmp	.L18
.L10:
	movl	-20(%rbp), %eax
	cmpl	%eax, -12(%rbp)
	jge	.L12
	leaq	.LC8(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	jmp	.L15
.L12:
	movl	-20(%rbp), %eax
	cmpl	%eax, -12(%rbp)
	jle	.L14
	leaq	.LC9(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	jmp	.L15
.L14:
	leaq	.LC10(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L15
.L9:
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$1, %edi
	call	exit@PLT
.L18:
	call	__stack_chk_fail@PLT
.L17:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	main, .-main
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
