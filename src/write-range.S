.intel_syntax noprefix
.global main
main:
	mov r12, 0
loop:
	add r12, 1
	mov rdi, r12
	call writei32
	mov r13, r12
	sub r13, 1000
	jz exit
	jmp loop
exit:
	call finish
