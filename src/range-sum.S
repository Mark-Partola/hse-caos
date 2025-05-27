	.intel_syntax noprefix
	.global main
	.text
main:
	call readi64
	mov rcx, rax
	mov rax, 0
	cmp rcx, 0
	jle fin
sum:
	add rax, rcx
	dec rcx
	jz print
	jmp sum
print:
	mov rdi, rax
	call writei64
	jmp main
fin:
	call finish
