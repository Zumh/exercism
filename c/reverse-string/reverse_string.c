#include "reverse_string.h"
#include <string.h>
#include <stdlib.h>
char *reverse(const char *value)
{
	// length of input value 
	int value_length = strlen(value);
	// since the paramter is receiving constant string
	// we can allocate memory and return that allocated address
	// make a copy of the string reverse it and return 
	char* rev_string = (char*) calloc(value_length + 1, sizeof(char));
	if (!rev_string)
	{
		free(rev_string);

		return NULL;
	}
	// two pointer that point start and end of the string
	int start = 0;
	int end = strlen(value) - 1;

	// here we going to traverse until they meet each other in the middle 
	while (start <= end) 
	{
		// we will swap character from both side 
		rev_string[start] = value[end];
		rev_string[end] = value[start];

		start++;
		end--;

	}

	return rev_string;
}
