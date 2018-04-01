/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <stdio.h>
#include "include/library.h"

int main(int argc, char **argv)
{
    printf("Hello C World\n");
}

/*
    char *strcpy (char *dest, char *src) - Copy src string string into dest string.
    char *strncpy(char *string1, char *string2, int n) - Copy first n characters of string2 to stringl .
    int strcmp(char *string1, char *string2) - Compare string1 and string2 to determine alphabetic order.
    int strncmp(char *string1, char *string2, int n) - Compare first n characters of two strings.
    int strlen(char *string) - Determine the length of a string.

    char *strncat(char *dest, const char *src, int n); - Concatenate n chracters from string src to the string dest.
    char *strrchr(char *string, int c) - Find last occurrence of character c in string.
    char *strstr(char *string2, char string*1) - Find first occurrence of string string1 in string2.
    char *strtok(char *s, const char *delim) - Parse the string s into tokens using delim as delimiter.
    //Equivalents
    char *strchr(char *string, int c) - Find first occurrence of character c in string.
    int strIndex(const char *sourceString, int searchCharacter, int occurrence);
    
//Dangerous
    char *strcat(char *dest, const char *src); - Concatenate string src to the string dest.

*/

/*
cd ~/projects/HelloWorldC/src
gcc helloworld.c ../bin/library.o -o ../bin/helloworld
*/
