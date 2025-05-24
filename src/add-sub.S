.intel_syntax noprefix
.global main
main:
	call readi64
	mov r12, rax

	call readi64
	mov r13, rax
	
	call readi64
	mov r14, rax	

	cmp r13, 0
	je add

	sub r12, r14
	jmp print

add:
	add r12, r14
	jmp print

print:
	mov rdi, r12
	call writei64
	call finish
