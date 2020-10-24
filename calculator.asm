%include "myStdlib.inc"

section .bss
	INT256 num
	BUFF string

section .data
	CONST_STR prompt, "STRING: "
	CONST_STR str_equals, "STR = "
	CONST_STR num_equals, "NUM = "

section .text
	global _start

_start:
	PRINT_STR prompt
	GET_STR string

	STR_TOINT string, num, 10 
	PRINT_STR num_equals
	PRINT_INT num, 10
	PRINT_STR endl
	PRINT_STR str_equals
	PRINT_STR string
	PRINT_STR endl

	INT_TOSTR num, string, 10
	PRINT_STR num_equals
	PRINT_INT num, 10
	PRINT_STR endl
	PRINT_STR str_equals
	PRINT_STR string
	PRINT_STR endl

	exit
