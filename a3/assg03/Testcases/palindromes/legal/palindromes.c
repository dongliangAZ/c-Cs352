/*
 * File: palindrome.c
 * Author: Saumya Debray
 * Purpose: Repeatedly reads in words from stdin and prints out 1 or 0 depending
 *      on whether or not the word read in as a palindrome.
 * Assumptions: Assumes that each word is at most 64 characters long.
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
 * is_palindrome(s) -- returns 1 if the string s is a palindrome, 0 otherwise.
 * Assumes that s is not NULL.
 */
int is_palindrome(char s[])
{
    int i, j;

    for (i = 0, j = strlen(s) - 1; i <= j; i++, j--) {
	if (tolower(s[i]) != tolower(s[j])) {
	    return 0;
	}
    }

    return 1;
}

int main()
{
    char buf[65];		/* accommodates strings of length up to 64 */
    int n;

    while ((n = scanf("%s", buf)) > 0) {
	printf("%d\n", is_palindrome(buf));
    }

    return 0;
}
