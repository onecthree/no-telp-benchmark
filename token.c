#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>


#define C_NULL 			'\0'
#define C_WSPACE		' '

bool static isvalid_number_phone( char const* number_phone )
{
	char   			char_src;
	int    			char_index = 0;

	int             prefix_index = 0;
	char const* 	prefix_pattern = "08+628";

	int             postfix_index = 0;
	int             postfix_t_length = 0;
	int             postfix_step = 2;
	char const* 	postfix_pattern = "17181959777879";

	bool is_prefix_found = false;

	while( (char_src = number_phone[char_index]) != C_NULL )
	{
		++char_index;

		if( char_src == C_WSPACE )
		{
			continue;
		}

		if( !is_prefix_found )
		{
			if( char_src == prefix_pattern[prefix_index] )
			{
				++prefix_index;
				goto prefix_match;
			}

			prefix_index = 2;
			if( char_src == prefix_pattern[prefix_index] )
			{
				++prefix_index;
				continue;
			}
			prefix_index = 0;

			prefix_match:
			if( prefix_index == 2 || prefix_index == 6 )
			{
				is_prefix_found = true;
			}
		}
		else
		{
			--char_index;
			int st_index = char_index;
			while( true )
			{

				if( char_src == postfix_pattern[postfix_index] )
				{
					++postfix_t_length;
					++postfix_index;
					++char_index;
					char_src = number_phone[char_index];
					continue;
				}

				if( postfix_t_length < 2 )
				{
					postfix_t_length = 0;
					postfix_index = postfix_step;
					postfix_step += 2;
					char_index = st_index;
					char_src = number_phone[char_index];
				}
				else
				{
					return true;
				}

				if( postfix_step > 14 )
				{
					goto ret_false;
				}
			}
		}
	}

	ret_false:
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