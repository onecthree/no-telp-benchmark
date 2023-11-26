
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

static bool isvalid_number_phone( char const* number_phone )
{
	if( strncmp("0817", number_phone, 4) == 0 || 
	strncmp("0818", number_phone, 4) == 0 ||
	strncmp("0819", number_phone, 4) == 0 ||
	strncmp("0859", number_phone, 4) == 0 ||
	strncmp("0877", number_phone, 4) == 0 ||
	strncmp("0878", number_phone, 4) == 0 ||
	strncmp("0879", number_phone, 4) == 0 ||
	strncmp("+62817", number_phone, 6) == 0 ||
	strncmp("+62818", number_phone, 6) == 0 ||
	strncmp("+62819", number_phone, 6) == 0 ||
	strncmp("+62859", number_phone, 6) == 0 ||
	strncmp("+62877", number_phone, 6) == 0 ||
	strncmp("+62878", number_phone, 6) == 0 ||
	strncmp("+62879", number_phone, 6) == 0 ||
	strncmp("+62 817", number_phone, 7) == 0 ||
	strncmp("+62 818", number_phone, 7) == 0 ||
	strncmp("+62 819", number_phone, 7) == 0 ||
	strncmp("+62 859", number_phone, 7) == 0 ||
	strncmp("+62 877", number_phone, 7) == 0 ||
	strncmp("+62 878", number_phone, 7) == 0 ||
	strncmp("+62 879", number_phone, 7) == 0 )
	{
		return true;
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

	return 0;
}