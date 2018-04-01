/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <stdio.h>
#include "include/minunit.h"

int tests_run = 0;
int tests_failed = 0;

int foo = 7;
int bar = 6;

static char *
test_foo ()
{
  Assert_AreEqual (7, foo, "error, foo != 7");
  Assert_AreNotEqual (7, foo, "foo == 7");
  return 0;
}

static char *
test_bar ()
{
  Assert_AreEqual (5, bar, "error, bar != 5");
  return 0;
}

static char *
all_tests ()
{
  mu_run_test (test_foo);
  mu_run_test (test_bar);
  return 0;
}

int
main (int argc, char **argv)
{
  char *result = all_tests ();
  if (result != 0)

    {
      printf ("%s\n", result);
    }
  else
    {
      printf ("ALL TESTS PASSED!\n");
    }
  printf ("Tests run: %d passed: %d failed: %d\n", tests_run,
   tests_run - tests_failed, tests_failed);

  return result != 0;
}

/*
    char *strcpy (char *dest, char *src) - Copy src string string into dest string.
    char *strncpy(char *string1, char *string2, int n) - Copy first n characters of string2 to stringl .
    int strcmp(char *string1, char *string2) - Compare string1 and string2 to determine alphabetic order.
    int strncmp(char *string1, char *string2, int n) - Compare first n characters of two strings.
    int strlen(char *string) - Determine the length of a string.
    char *strcat(char *dest, const char *src); - Concatenate string src to the string dest.
    char *strncat(char *dest, const char *src, int n); - Concatenate n chracters from string src to the string dest.
    char *strchr(char *string, int c) - Find first occurrence of character c in string.
    char *strrchr(char *string, int c) - Find last occurrence of character c in string.
    char *strstr(char *string2, char string*1) - Find first occurrence of string string1 in string2.
    char *strtok(char *s, const char *delim) - Parse the string s into tokens using delim as delimiter.
*/
