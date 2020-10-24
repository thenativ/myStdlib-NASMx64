SIZE_INT32 equ 32; 32-bit
SIZE_INT64 equ 64; 64-bit
SIZE_INT256 equ 256; 256-bit

%macro INTPTR 1
	%1 resb 8
%endmacro

%macro INT256 1
	%1 resb SIZE_INT256;
%endmacro

%macro PRINT_INT 1
	mov rax, [%1]
	mov rcx, INT_BUFFER
	mov rbx, 10
	call _PRINTBUFFER
%endmacro

%macro INT_TOSTR 3
	mov rax, [%1]
	mov rcx, %2
	mov rbx, %3
	call __INT_TOSTRING
%endmacro

section .bss
	INT256 INT_BUFFER
	INTPTR INT_P


section .text

__INT_TOSTRING:
	
	mov [INT_P], rcx
	push 0

__INT_TOSTRING_ASCII:
	
	xor rdx, rdx
	div rbx
	add rdx, 48
	push rdx
	inc rcx
	cmp rax, 0
	jne __INT_TOSTRING_ASCII
	mov rcx, 0

__INT_TOSTRING_BYTES:
	
	pop rdx
	mov [INT_P+rcx], dl
	inc rcx
	cmp rdx, 0
	jne __INT_TOSTRING_BYTES

	mov rdx, rcx
	mov rsi, INT_P

	ret


