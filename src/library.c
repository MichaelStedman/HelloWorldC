/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/
///
/// The library.c file contains the primary functions used by HelloWorld. These
/// are focussed on providing the same string functions that I've used previously
/// in Basic and C#. These functions always return a new copy of the string with
/// the required changes rather than mutating the original string.
///

#include "include/library.h"

double strStrToDouble(const char *sourceString)
{
    return strtod(sourceString, NULL);
}

float strStrToFloat(const char *sourceString)
{

    return strtof(sourceString, NULL);
}

//float strStrToFloat(const char *sourceString)
//{
//   return atof(sourceString);
//}

 int strStrToInt(const char *sourceString)
{
    return atoi(sourceString);
}

char *strIntToStr(int value)
{
    char *result = malloc(11);
    sprintf(result, "%d", value);
    return result;
}

char *strLPad(const char *sourceString, char padChar, int length)
{
    char *result = malloc(length + 1);
    int i;
    for (i = 0; i < length; i++) {
        result[i] = padChar;
    }
    int start = length - strlen(sourceString);
    if (start < 0)
        start = 0;
    strncpy(result + start, sourceString, length);
    return result;
}

char *strRPad(const char *sourceString, char padChar, int length)
{
    char *result = malloc(length + 1);
    int i;
    for (i = 0; i < length; i++) {
        result[i] = padChar;
    }
    strncpy(result, sourceString,
            length < strlen(sourceString) ? length : strlen(sourceString));
    return result;
}

char *strTrim(const char *sourceString)
{
    return strStrip(sourceString, ' ');
}

char *strStrip(const char *sourceString, char padChar)
{
    assert(sourceString);
    int sourceStringLength = strlen(sourceString);
    char *temp = malloc(sourceStringLength + 1);
    int sp = 0;
    int dp = 0;

    // ignore leading padding chars
    while (sp < sourceStringLength && sourceString[sp] == padChar) {
        sp++;
    }

    // copy everything except duplicates of padding character
    while (sp < sourceStringLength) {

        // Copy non padding characters
        while (sp < sourceStringLength && sourceString[sp] != padChar) {
            temp[dp++] = sourceString[sp++];
        }

        // Copy the first padding character
        if (sp < sourceStringLength) {
            temp[dp++] = sourceString[sp++];
        }
        // Ignore subsequent padding characters
        while (sp < sourceStringLength && sourceString[sp] == padChar) {
            sp++;
        }
    }

    // Pad to full length
    while (dp < sourceStringLength) {
        temp[dp++] = padChar;
    }

    char *result = strRStrip(temp, padChar);
    free(temp);
    temp = NULL;
    return result;
}

char *strRStrip(const char *sourceString, char padChar)
{
    assert(sourceString);

    // Find the last non padding character by working
    // backwards from the end of the sourceString
    int length = strlen(sourceString) - 1;
    while (length > 0 && sourceString[length] == padChar) {
        length--;
    }
    length++;

    // Create a buffer big enough for the sourceString
    // without the trailing padding characters plus the terminating NULL
    char *result = malloc(length + 1);

    // Do the copy from the middle of the sourceString
    strncpy(result, sourceString, length);

    // Add the terminating NULL character
    result[length] = '\0';
    return result;
}

char *strLTrim(const char *sourceString)
{
    return strLStrip(sourceString, ' ');
}

char *strRTrim(const char *sourceString)
{
    return strRStrip(sourceString, ' ');
}

char *strLStrip(const char *sourceString, char padChar)
{
    assert(sourceString);

    // Find the first non padding character by working
    // forwards from the start of the sourceString
    int start = 0;
    while (start < strlen(sourceString) && sourceString[start] == padChar) {
        start++;
    }
    // Create a buffer big enough for the sourceString//without the leading
    // padding characters plus the terminating NULL
    int length = strlen(sourceString) - start;
    char *result = malloc(length + 1);

    // Do the copy from the middle of the sourceString
    strncpy(result, sourceString + start, length);

    // Add the terminating NULL character
    result[length] = '\0';
    return result;
}

char *strMid(const char *sourceString, int start, int length)
{
    assert(sourceString);
    assert(start >= 0);
    int sourceStringLength = strlen(sourceString);
    assert(start < sourceStringLength);
    assert(length > 0);

    if (length > sourceStringLength) {
        length = sourceStringLength;
    }
    // Create a buffer big enough for the string plus terminating NULL
    char *result = malloc(length + 1);
    assert(result);

    // Do the copy from the middle of the sourceString
    strncpy(result, sourceString + start, length);

    // Add the terminating NULL character
    result[length] = '\0';
    return result;
}

char *strRight(const char *sourceString, int length)
{
    assert(sourceString);
    assert(length > 0);

    int sourceStringLength = strlen(sourceString);

    if (length > sourceStringLength) {
        length = sourceStringLength;
    }
    // Create a buffer big enough for the string plus terminating NULL
    char *result = malloc(length + 1);
    assert(result);

    // Do the copy from the end of the sourceString
    strncpy(result, sourceString + sourceStringLength - length, length);

    // Add the terminating NULL character
    result[length] = '\0';
    return result;
}

char *strLeft(const char *sourceString, int length)
{
    assert(sourceString);
    assert(length > 0);

    int sourceStringLength = strlen(sourceString);
    if (length > sourceStringLength) {
        length = sourceStringLength;
    }
    // Create a buffer big enough for the string plus terminating NULL
    char *result = malloc(length + 1);
    assert(result);

    // Do the copy from the front of the sourceString
    strncpy(result, sourceString, length);

    // Add the terminating NULL character
    result[length] = '\0';
    return result;
}

char *strConcat(int num, ...)
{
    int totalLength = 0;
    va_list arg;

    // How long will the final string be?
    // Iterate over the arguments and sum their lengths
    va_start(arg, num);
    int i;
    for (i = 0; i < num; i++) {
        char *ptr = va_arg(arg, char *);
        totalLength += strlen(ptr);
    }
    va_end(arg);

    // Allocate enough room for the result string plus the terminating NULL
    char *result = calloc(1, totalLength + 1);
    assert(result);

    // Copy each source string into the result string
    va_start(arg, num);
    for (i = 0; i < num; i++) {
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

    // Upper case the first character
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
    // Copy the terminating NULL character
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
