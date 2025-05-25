	.intel_syntax noprefix
	.global main
main:
	xor r12, r12
	call readi64
	mov r13, rax
loop:
	inc r12
	mov rdi, r12
	call writei64
	mov rdi, r12
	sub rdi, r13
	jl loop
	call finish
