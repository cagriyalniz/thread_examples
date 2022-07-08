	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15, 6
	.globl	_routine                ## -- Begin function routine
	.p2align	4, 0x90
_routine:                               ## @routine
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$0, -4(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$10000, -4(%rbp)        ## imm = 0x2710
	jge	LBB0_3
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movq	_mutex@GOTPCREL(%rip), %rdi
	callq	_pthread_mutex_lock
	movq	_mutex@GOTPCREL(%rip), %rdi
	movl	_mails(%rip), %ecx
	addl	$1, %ecx
	movl	%ecx, _mails(%rip)
	movl	%eax, -8(%rbp)          ## 4-byte Spill
	callq	_pthread_mutex_unlock
	movl	-4(%rbp), %ecx
	addl	$1, %ecx
	movl	%ecx, -4(%rbp)
	jmp	LBB0_1
LBB0_3:
	xorl	%eax, %eax
                                        ## kill: def $rax killed $eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$80, %rsp
	movq	_mutex@GOTPCREL(%rip), %rdi
	xorl	%eax, %eax
	movl	%eax, %esi
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, -8(%rbp)
	movl	$0, -52(%rbp)
	movl	$0, -56(%rbp)
	callq	_pthread_mutex_init
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$4, -56(%rbp)
	jge	LBB1_7
## %bb.2:                               ##   in Loop: Header=BB1_1 Depth=1
	xorl	%eax, %eax
	movl	%eax, %ecx
	leaq	_routine(%rip), %rdx
	leaq	-48(%rbp), %rsi
	movslq	-56(%rbp), %rdi
	shlq	$3, %rdi
	addq	%rdi, %rsi
	movq	%rsi, %rdi
	movq	%rcx, %rsi
	callq	_pthread_create
	cmpl	$0, %eax
	je	LBB1_4
## %bb.3:
	leaq	L_.str(%rip), %rdi
	callq	_perror
	movl	$1, -52(%rbp)
	jmp	LBB1_8
LBB1_4:                                 ##   in Loop: Header=BB1_1 Depth=1
	movl	-56(%rbp), %esi
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	xorl	%ecx, %ecx
	movl	%ecx, %esi
	movslq	-56(%rbp), %rdx
	movq	-48(%rbp,%rdx,8), %rdi
	movl	%eax, -60(%rbp)         ## 4-byte Spill
	callq	_pthread_join
	cmpl	$0, %eax
	je	LBB1_6
## %bb.5:
	movl	$2, -52(%rbp)
	jmp	LBB1_8
LBB1_6:                                 ##   in Loop: Header=BB1_1 Depth=1
	movl	-56(%rbp), %esi
	leaq	L_.str.2(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	-56(%rbp), %ecx
	addl	$1, %ecx
	movl	%ecx, -56(%rbp)
	jmp	LBB1_1
LBB1_7:
	movq	_mutex@GOTPCREL(%rip), %rdi
	callq	_pthread_mutex_destroy
	movl	_mails(%rip), %esi
	leaq	L_.str.3(%rip), %rdi
	movl	%eax, -64(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
LBB1_8:
	movl	-52(%rbp), %eax
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	-8(%rbp), %rdx
	cmpq	%rdx, %rcx
	movl	%eax, -68(%rbp)         ## 4-byte Spill
	jne	LBB1_10
## %bb.9:
	movl	-68(%rbp), %eax         ## 4-byte Reload
	addq	$80, %rsp
	popq	%rbp
	retq
LBB1_10:
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	_mails                  ## @mails
.zerofill __DATA,__common,_mails,4,2
	.comm	_mutex,64,3             ## @mutex
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"fail"

L_.str.1:                               ## @.str.1
	.asciz	"Thread %d has started \n"

L_.str.2:                               ## @.str.2
	.asciz	"Thread %d has finished\n"

L_.str.3:                               ## @.str.3
	.asciz	"Number of mails: %d\n"

.subsections_via_symbols
