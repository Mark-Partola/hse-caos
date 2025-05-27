	.intel_syntax noprefix
	.global main
	.text
main:
	call readi64
	jc fin
	
	cmp rax, 1
	je append

	cmp rax, 2
	je remove

	jmp main
append:
	call readi64
	push rax
	jmp main
remove:
	pop rdi
	call writei64
	jmp main
fin:
	call finish
