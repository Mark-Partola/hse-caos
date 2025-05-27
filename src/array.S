	.intel_syntax noprefix
	.global main
	.text
main:
	call readi64
	mov r12, rax
	
	call readi64
	mov r13, rax

	lea r14, [rip + arr]
	lea r15, [r14 + 8 * r12] 
	mov rdi, [r15]
	call writei64
	mov [r15], r13
	
	cmp r13, 0
	jnz main

	call finish

	.bss
arr:
	.skip 200 * 8
