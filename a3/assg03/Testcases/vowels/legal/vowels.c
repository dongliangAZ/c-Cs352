/*
 * File: vowels.c
 * Author: Saumya Debray
 * Purpose: Repeatedly reads in words from stdin and prints out 1 or 0 depending
 *    on whether or not the vowels in the word occur in order.
 * Assumptions: assumes that each input word has length at most 64.
 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/*
 * vowels_in_order(s) -- returns 1 if the vowels occurring in the string s are
 * in order, 0 otherwise.
 * Assumes that the argument s is non-NULL.
 */
int vowels_in_order(char s[])
{
    char last_vowel, ch;
    int i;
    /*
     * check that s contains only letters.
     */
    for (i = 0; s[i] != '\0'; i++) {
	if (!isalpha(s[i])) {
	    fprintf(stderr, "Error: non-letter character %c in word %s\n",
		    s[i], s);
	    exit(1);
	}
    }
    /*
     * check that the vowels in s are in order
     */
    for (last_vowel = 'a', i = 0; s[i] != '\0'; i++) {
	ch = tolower(s[i]);

	switch (ch) {
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
	    if (ch < last_vowel) {
		/* ch is before last_vowel, i.e., they are not in order */
		return 0;
	    }
	    last_vowel = ch;
	    break;

	default:
	    continue;
	}
    }

    return 1;
}

int main()
{
    char buf[65];		/* accommodates strings of length up to 64 */
    int n;

    while ((n = scanf("%s", buf)) > 0) {
	printf("%d\n", vowels_in_order(buf));
    }

    return 0;
}
