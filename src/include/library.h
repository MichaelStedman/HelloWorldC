/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>
#include <stdarg.h>

char *strLPad(const char *sourceString, char padChar, int length);
char *strRPad(const char *sourceString, char padChar, int length);
char *strLeft(const char *sourceString, int length);
char *strMid(const char *sourceString, int start, int length);
char *strRight(const char *sourceString, int length);

char *strLStrip(const char *sourceString, char padChar);
char *strRStrip(const char *sourceString, char padChar);
char *strStrip(const char *sourceString, char padChar);
char *strLTrim(const char *sourceString);
char *strRTrim(const char *sourceString);
char *strTrim(const char *sourceString);

char *strConcat(int num, ...);

char *strChangeCase(const char *sourceString, bool upper);
char *strUpperCase(const char *sourceString);
char *strLowerCase(const char *sourceString);
char *strCapitalise(const char *sourceString);

bool strStartsWith(const char *sourceString, const char *searchString);
int strIndex(const char *sourceString, int searchCharacter,
             int occurrence);
