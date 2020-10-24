INT32_SIZE equ 32; 32-byte
INT64_SIZE equ 64; 64-byte
INT256_SIZE equ 256; 256-bytes

section .bss
	INT256 resb INT256_SIZE
	INT_P resb 8

%macro PRINT_INT 1
	mov rdx, %1
	mov rcx, INT256
	mov rbx, 1
	call _PRINTBUFFER
%endmacro

%macro INT_TOSTR 1
	call __INT_TOSTRING
%endmacro

section .text

__INT_TOSTRING:

	mov [INT_P], rcx
	push 0

__INT_TOSTRING_ASCII:

	xor rdx, rdx
	mov rbx, 10
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
