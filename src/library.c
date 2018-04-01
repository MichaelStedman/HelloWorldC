/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/
#include "include/library.h"
char *strCapitalise(const char *sourceString)
{
    char *destinationString = malloc(strlen(sourceString));
    strcpy(destinationString, sourceString);
    //Upper case the first character
    destinationString[0] = toupper(sourceString[0]);
/*
    //Copy the remaining characters
    int i = 1;

    while (sourceString[i]) {
        destinationString[i] = sourceString[i];
        i++;
    }

    //Copy the terminating NULL character
    destinationString[i] = sourceString[i];
*/
    return destinationString;
}

char *strLowerCase(const char *sourceString)
{
    char *destinationString = malloc(strlen(sourceString));
    int i = 0;

    while (sourceString[i]) {
        destinationString[i] = tolower(sourceString[i]);
        i++;
    }

    //Copy the terminating NULL character
    destinationString[i] = sourceString[i];
    return destinationString;
}

char *strUpperCase(const char *sourceString)
{
    char *destinationString = malloc(strlen(sourceString));
    int i = 0;

    while (sourceString[i]) {
        destinationString[i] = toupper(sourceString[i]);
        i++;
    }

    //Copy the terminating NULL character
    destinationString[i] = sourceString[i];
    return destinationString;
}

int strIndex(const char *sourceString, int searchCharacter, int occurrence)
{
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
