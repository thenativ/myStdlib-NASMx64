%include "Integer.inc"
%include "String.inc"

STDIN equ 0
STDOUT equ 1
STDERR equ 2

SYS_READ equ 0
SYS_WRITE equ 1
SYS_EXIT equ 60

endl db 10, 0

section .bss
	BUFF _STDBUFF

%macro exit 0
	mov rax, SYS_EXIT
	mov rdi, STDIN
	syscall
%endmacro

%macro PRINT_STR 1
	mov rdx, %1
	mov rbx, 0
	call _PRINTBUFFER
%endmacro

%macro PRINT_INT 2
	mov rax, [%1]
	mov rcx, _STDBUFF
	mov rbx, %2
	call _PRINTBUFFER
%endmacro

%macro GET_STR 1
	mov rax, %1
	call _SCANBUFFER
%endmacro

%macro GET_INT 1
	GET_STR %1
	STR_TOINT %1
%endmacro

section .text

_PRINTBUFFER:
	cmp rbx, 0
	je __PRINTBUFFER_STR
	cmp rbx, 64
	jle __PRINTBUFFER_INT
__PRINTBUFFER_INT:
	call __INT_TOSTRING
	jmp __PRINTBUFFER_SYSCALL
__PRINTBUFFER_STR:
	call __STR_SIZE
	jmp __PRINTBUFFER_SYSCALL
__PRINTBUFFER_SYSCALL:
	mov rax, SYS_WRITE
	mov rdi, STDOUT
	syscall
	ret

_SCANBUFFER:
	mov rsi, rax	; CHAR* BUFFER
	mov rax, SYS_READ
	mov rdi, STDIN
	mov rdx, BUFF_SIZE
	syscall
	ret
