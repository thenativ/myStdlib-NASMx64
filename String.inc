section .bss
	STR_P resb 8

%macro PRINT_STR 1
	mov rdx, %1
	mov rbx, 0
	call _PRINTBUFFER
%endmacro

%macro STR_TOINT 1
	mov rcx, %1
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

	mov [STR_P], rcx	
	mov rbx, 10
	xor rdx, rdx
	xor rax, rax

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
	mov [STR_P], rax
	ret
