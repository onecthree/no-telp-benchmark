#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define PCRE2_CODE_UNIT_WIDTH 8

#include <pcre2.h>


static bool isvalid_number_phone( char const* number_phone )
{
    char const* number_phones_list[21] = {
        "0817",
        "0818",
        "0819",
        "0859",
        "0877",
        "0878",
        "0879",

        "+62817",
        "+62818",
        "+62819",
        "+62859",
        "+62877",
        "+62878",
        "+62879",

        "+62 817",
        "+62 818",
        "+62 819",
        "+62 859",
        "+62 877",
        "+62 878",
        "+62 879",
    };

    int number_phones_len[21] = {
        4,
        4,
        4,
        4,
        4,
        4,
        4,

        6,
        6,
        6,
        6,
        6,
        6,
        6,
        
        7,
        7,
        7,
        7,
        7,
        7,
        7,
    };

    int index = 0;
    while( index < 21 )
    {
        if( strncmp(number_phones_list[index], number_phone, number_phones_len[index]) == 0 )
        {
            return true;
        }

        ++index;
    }

    return false;

}

int main( int argc, char* argv[] )
{
	if( argc < 2 )
	{
		exit(4);
	}

    if( isvalid_number_phone(argv[1]))
	{
		// puts("Nomor valid");
	}
	else
	{
		puts("Nomor tidak valid");
	}

	return 1;
}