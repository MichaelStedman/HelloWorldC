/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/
#include "include/library.h"
int functionToBeTested(int value)
{
    return value + 10;
}
/*
cd ~/projects/HelloWorldC/src
gcc -o ../bin/library.o -c library.c
*/