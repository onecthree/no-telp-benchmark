#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define PCRE2_CODE_UNIT_WIDTH 8

#include <pcre2.h>


static bool regexp_match(const char *pattern_v, const char *subject_v )
{
    int errorcode;
    size_t resultlen;
    PCRE2_SIZE erroroffset;
    PCRE2_UCHAR *result;
    PCRE2_SPTR pattern = pattern_v;
    PCRE2_SPTR subject = subject_v; 
    pcre2_code *regexp = pcre2_compile(pattern, PCRE2_ZERO_TERMINATED, PCRE2_UTF, &errorcode, &erroroffset, NULL);

    if(regexp)
    {
        pcre2_match_data *match_data = pcre2_match_data_create_from_pattern(regexp, NULL);

        if(pcre2_match(regexp, subject, strlen((char *)subject), 0, 0, match_data, NULL) >= 0)
        {
            pcre2_substring_get_bynumber(match_data, 0, &result, &resultlen);
        } else {
            result = NULL;
            resultlen = 0;
        }

        pcre2_match_data_free(match_data);
        pcre2_code_free(regexp);
    } else {
        PCRE2_UCHAR error[256];
        pcre2_get_error_message(errorcode, error, sizeof(error));
    }

    if( result )
        return true;

    return false;
}

int main( int argc, char* argv[] )
{
	if( argc < 2 )
	{
		exit(4);
	}

	if( regexp_match("^(0817|0818|0819|0859|0877|0878|0879|\\+62817|\\+62818|\\+62819|\\+62859|\\+62877|\\+62878|\\+62879|\\+62\\s817|\\+62\\s818|\\+62\\s819|\\+62\\s859|\\+62\\s877|\\+62\\s878|\\+62\\s879)", argv[1]) )
	{
		// puts("Nomor valid");
	}
	else
	{
		puts("Nomor tidak valid");
	}

	return 1;
}