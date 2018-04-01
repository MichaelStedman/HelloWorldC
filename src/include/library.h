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

int strIndex(const char *sourceString, int searchCharacter, int occurrence);
char *strChangeCase(const char *sourceString, bool upper);
char *strUpperCase(const char *sourceString);
char *strLowerCase(const char *sourceString);
char *strCapitalise(const char *sourceString);