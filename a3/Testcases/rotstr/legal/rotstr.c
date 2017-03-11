/*
 * File: rotstr.c
 * Author: Saumya Debray
 * Purpose: Read in an integer N followed by some number of alphanumeric
 *	strings.  For each string S, rotate the letters in S by N.
 * Assumptions: assumes that each input string is at most 64 chars long.
 */

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/*
 * StringIsAlnum(s) -- returns true if the string s contains only alphanumeric
 * characters, false otherwise.  Assumes s is non-NULL.
 */
bool
StringIsAlnum (char *s)
{
  for (; *s != '\0'; s++)
    {
      if (!isalnum (*s))
	{
	  return false;
	}
    }

  return true;
}

/*
 * rotate_char(ch, n) takes an alphabetic character ch and an integer n and
 * returns the character obtained by rotating ch forward by n.
 *
 * Assumptions: ch is a letter; n lies between 0 and 25.
 */
int
rotate_char (int ch, int n)
{
  int initial_offset, final_offset, rotated_char;

  initial_offset = isupper (ch) ? ch - 'A' : ch - 'a';
  final_offset = (initial_offset + n) % 26;

  rotated_char = isupper (ch) ? final_offset + 'A' : final_offset + 'a';

  return rotated_char;
}


/*
 * rotate_str(str, n) -- given a string str and an integer n, rotates
 * each letter in str by n.
 *
 * Assumptions: str is non-NULL; n is non-negative.
 */
void
rotate_str (char *str, int n)
{
  char ch;

  while (*str != '\0')
    {
      ch = *str;
      if (isalpha (ch))
	{
	  *str = rotate_char (ch, n);
	}

      str++;
    }
}



/*
 * main: reads in input strings, checks them for illegal characters, rotates
 * them and prints them out.
 */
int
main ()
{
  int n, status;
  char buf[65];			// from assumpption that input strings are at most 64 chars long
  int error_occurred = 0;


  status = scanf ("%d", &n);	// n = rotation amount

  if (status != 1)
    {				// wasn't able to read an integer
      fprintf (stderr, "ERROR: first input must be an integer\n");
      return 1;
    }

  n = n % 26;			// bring n into the range [-25, 25] if necessary.
  n = (n + 26) % 26;		// translate negative rotation amounts into positive ones

  /*
   * Now repeatedly read in strings; check that they are alphanumeric; rotate
   * the characters; and print the result.
   */
  while (scanf ("%s", buf) != EOF)
    {
      if (!StringIsAlnum (buf))
	{
	  fprintf (stderr, "ERROR: string is not alphanumeric: %s\n", buf);
	  error_occurred = 1;
	  continue;
	}

      rotate_str (buf, n);

      printf ("%s\n", buf);
    }

  return error_occurred;

}
