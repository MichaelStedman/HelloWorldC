/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/
#include "include/library.h"
char *strConcat(int num, ...)
{
    int totalLength = 0;
    va_list arg;
    int done;


    // How long will the final string be?
    // Iterate over the arguments and sum their lengths
    va_start(arg, num);
    for (int i = 0; i < num; i++) {
        char *ptr = va_arg(arg, char *);
        totalLength += strlen(ptr);
    }
    va_end(arg);

    // Allocate enough room for the result string plus the terminating NULL
    char *result = malloc(totalLength + 1);
    assert(result);

    // Copy each source string into the result string
    va_start(arg, num);
    for (int i = 0; i < num; i++) {
        char *ptr = va_arg(arg, char *);
        strncat(result, ptr, strlen(ptr));
    }
    va_end(arg);
    return result;
}

bool strStartsWith(const char *sourceString, const char *searchString)
{
    return strncmp(sourceString, searchString,
                   strlen(searchString)) == 0 ? true : false;
}

char *strCapitalise(const char *sourceString)
{
    assert(sourceString);

    char *destinationString = malloc(strlen(sourceString));
    assert(destinationString);

    strcpy(destinationString, sourceString);

    //Upper case the first character
    destinationString[0] = toupper(sourceString[0]);

    return destinationString;
}

char *strChangeCase(const char *sourceString, bool upper)
{
    assert(sourceString);

    char *destinationString = malloc(strlen(sourceString));
    assert(destinationString);

    int i = 0;

    while (sourceString[i]) {
        destinationString[i] =
            upper ? toupper(sourceString[i]) : tolower(sourceString[i]);
        i++;
    }

    //Copy the terminating NULL character
    destinationString[i] = sourceString[i];
    return destinationString;
}

char *strLowerCase(const char *sourceString)
{
    assert(sourceString);

    return strChangeCase(sourceString, false);
}

char *strUpperCase(const char *sourceString)
{
    assert(sourceString);

    return strChangeCase(sourceString, true);
}

int strIndex(const char *sourceString, int searchCharacter, int occurrence)
{
    assert(sourceString);

    int count = 0;
    int offset = 0;
    while (1) {
        const char *startPoint =
            strchr(sourceString + offset, searchCharacter);
        count++;
        if (startPoint == NULL)
            return -1;
        if (count == occurrence) {
            return (void *) startPoint - (void *) sourceString;
        }
        offset = (void *) startPoint - (void *) sourceString + 1;
    }
    return 0;
}

/*
cd ~/projects/HelloWorldC/src
gcc -o ../bin/library.o -c library.c
*/
