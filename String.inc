BUFF_SIZE equ 256

section .bss
	STR_P resb 8

%macro BUFF 1
	%1 resb BUFF_SIZE;
%endmacro

%macro CONST_STR 2
	%1 db %2, 0
%endmacro

%macro STR_TOINT 3
	mov rcx, %1
	mov rdx, %2
	mov rbx, %3
	call __STR_TOINT
%endmacro

section .text

__STR_SIZE:

	push rdx
	mov rsi, rdx
	xor rdx, rdx

__STR_SIZE_LOOP:

	mov cl, [rsi]
	cmp cl, 0
	je __STR_SIZE_DONE
	inc rdx
	inc rsi
	jne __STR_SIZE_LOOP

__STR_SIZE_DONE:
	pop rsi
	ret


__STR_TOINT:	
	
	push rdx
	xor rax, rax
	xor rdx, rdx

__STR_TOINT_ASCII:
	
	mov dl, byte [rcx]
        cmp dl, 48
        jl __STR_TOINT_DONE
	cmp dl, 57
        jg __STR_TOINT_DONE
	push rdx
        mul rbx
	pop rdx
        sub rdx, 48
	add rax, rdx
        inc rcx
	jmp __STR_TOINT_ASCII

__STR_TOINT_DONE:
	pop rcx
	mov [rcx], rax
	ret

