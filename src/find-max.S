	.intel_syntax noprefix
	.global main
	.text
main:
	lea r12, [rip + arr]
	mov r13, 0
fill: 
	call readi64
	lea r14, [r12 + 8 * r13]
	mov [r14], rax
	inc r13

	cmp r13, 5
	je find
	jmp fill
find:
	mov rax, [r12]
	mov rcx, 1
loop:
	cmp rcx, 5
	je print
	mov r13, [r12 + 8 * rcx]
	inc rcx
	cmp rax, r13
	jge loop
	mov rax, r13
	jmp loop
print:
	mov rdi, rax
	call writei64
fin:
	call finish

	.bss
arr:
	.skip 8 * 5
