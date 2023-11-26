#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


#define C_NULL 			'\0'
#define C_WSPACE		' '
#define RESV_T_08		4856
#define RESV_T_P628		43545056

#define POSTFIX_A1		4955
#define POSTFIX_A2		4956
#define POSTFIX_A3		4957
#define POSTFIX_A4		5357
#define POSTFIX_A5		5555
#define POSTFIX_A6		5556
#define POSTFIX_A7		5557

bool isvalid_number_phone( char const* number_phone )
{
	char   	char_src;
	int    	char_index = 0;

	int   	prefix_reserv = 0;

	int    	prefix_gs = 0;
	int     postfix_gs = 0;

	while( (char_src = number_phone[char_index]) != C_NULL )
	{
		if( postfix_gs > 6000 )
		{
			break;
		}

		++char_index;

		if( char_src == C_WSPACE )
		{
			continue;
		}

		if( !prefix_reserv )
		{
			prefix_gs = (prefix_gs * 100) + char_src;


			if( prefix_gs == RESV_T_08 || prefix_gs == RESV_T_P628 )
			{
				prefix_reserv = true;
			}
		}
		else
		{
			postfix_gs = (postfix_gs * 100) + char_src;

			switch( postfix_gs )
			{
				case POSTFIX_A1:
				case POSTFIX_A2:
				case POSTFIX_A3:
				case POSTFIX_A4:
				case POSTFIX_A5:
				case POSTFIX_A6:
				case POSTFIX_A7:
					return true;
				break;
			}
		}

	}

	return false;
}


int main( int argc, char* argv[] )
{
	if( argc < 2 )
	{
		exit(1);
	}

	if( isvalid_number_phone(argv[1]) )
	{
		// puts("Nomor valid");
	}
	else
	{
		puts("Nomor tidak valid");
	}
}