#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>


#define C_NULL 			'\0'
#define C_WSPACE		' '
#define RESV_T_08		4856
#define RESV_T_P628		43545056

#define POSTFIX_A1		48564955
#define POSTFIX_A2		48564956
#define POSTFIX_A3		48564957
#define POSTFIX_A4		48565357
#define POSTFIX_A5		48565555
#define POSTFIX_A6		48565556
#define POSTFIX_A7		48565557

#define POSTFIX_A8		435450564955
#define POSTFIX_A9		435450564956
#define POSTFIX_A10		435450564957
#define POSTFIX_A11		435450565357
#define POSTFIX_A12		435450565555
#define POSTFIX_A13		435450565556
#define POSTFIX_A14		435450565557

#define MAX_Q           435450565557

bool static isvalid_number_phone( char const* number_phone )
{
	char   		char_src;
	int    		char_index = 0;

	uint64_t 	number = 0;

	while( (char_src = number_phone[char_index]) != C_NULL )
	{
		if( number > MAX_Q )
		{
			break;
		}

		++char_index;

		if( char_src == C_WSPACE )
		{
			continue;
		}

		number = (number * 100) + char_src;

		if( number < POSTFIX_A1 )
		{
			continue;
		}

		switch( number )
		{
			case POSTFIX_A1:
			case POSTFIX_A2:
			case POSTFIX_A3:
			case POSTFIX_A4:
			case POSTFIX_A5:
			case POSTFIX_A6:
			case POSTFIX_A7:
			case POSTFIX_A8:
			case POSTFIX_A9:
			case POSTFIX_A10:
			case POSTFIX_A11:
			case POSTFIX_A12:
			case POSTFIX_A13:
			case POSTFIX_A14:
				return true;
			break;
		}

	}

	return false;
}


int main( int argc, char* argv[] )
{
	if( argc < 2 )
	{
		exit(4);
	}

	if( isvalid_number_phone(argv[1]) )
	{
		// puts("Nomor valid");
	}
	else
	{
		puts("Nomor tidak valid");
	}

	return 1;
}