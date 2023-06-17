#include "acronym.h"
#include <ctype.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char *abbreviate(const char *phrase) {
    if (!phrase) return NULL;

    size_t out_len = 0;
    enum {FIRST_LETTER, SEPARATOR} looking_for = FIRST_LETTER;
    const char *p = phrase;
    char *abbr = NULL;

    if (strlen(phrase) <= 0)
    {
	    return NULL;
    }
    while (*p) {
        char ch = *p;
        unsigned char uch = ch;
        switch (looking_for) {
            case FIRST_LETTER:
                if (isalpha(uch))
		{
			if (abbr == NULL) 
			{
				abbr = (char*) calloc(1, sizeof(char));
				if (!abbr)
				{
					free(abbr);
					return NULL;
				}
			}
			else
			{
				abbr = realloc(abbr, (out_len + 1) * sizeof(char));
				if (!abbr) {
                        		free(abbr);
                        		return NULL;
                    		}

			}
			abbr[out_len] = toupper(uch);
                    	out_len++;
                    	looking_for = SEPARATOR;
                }
                break;
            case SEPARATOR:
                if (isspace(uch) || ch == '-') {
                    looking_for = FIRST_LETTER;
                }
                break;
        }
        p++;
    }

    abbr = realloc(abbr, (out_len + 1) * sizeof(char));
    if (!abbr) {
        free(abbr);
        return NULL;
    }
    abbr[out_len] = '\0';
    return abbr;
}

