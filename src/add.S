.intel_syntax noprefix
.global main
main:
	call readi64
	mov rbx, rax
	call readi64
	add rbx, rax
	mov rdi, rbx
	call writei64
	call finish
