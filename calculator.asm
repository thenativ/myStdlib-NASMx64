%include "myStdlib.inc"

section .bss
	INT256 num
	BUFF string

section .data
	enter_string db "STRING: ", 0
	print_string db "STR = ", 0
	print_num db "NUM = ", 0

section .text
	global _start

_start:
	PRINT_STR enter_string
	GET_STR string

	STR_TOINT string, num, 10 
	PRINT_STR print_num
	PRINT_INT num
	PRINT_STR endl
	PRINT_STR print_string
	PRINT_STR string
	PRINT_STR endl

	INT_TOSTR num, string, 10
	PRINT_STR print_num
	PRINT_INT num
	PRINT_STR endl
	PRINT_STR print_string
	PRINT_STR string
	PRINT_STR endl
	exit
