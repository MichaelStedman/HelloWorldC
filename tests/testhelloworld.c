/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/minunit.h"
#include "../src/include/library.h"

int tests_run = 0;
int tests_failed = 0;

int foo = 7;
int bar = 5;

static char *test_functionToBeTested()
{
    int value = 35;
    int actual = functionToBeTested(35);
    int expected = 45;

    char *str3 = malloc(80);
    sprintf(str3, "Expected %d Actual %d", expected, actual);

    Assert_AreEqual(expected, actual, str3);

    free(str3);

    return 0;
}

static char *test_foo()
{
    Assert_AreEqual(7, foo, "error, foo != 7");
    return 0;
}

static char *test_bar()
{
    char *str = "error, bar != 5";
    Assert_AreEqual(5, bar, str);
    return 0;
}

static char *all_tests()
{
    mu_run_test(test_foo);
    mu_run_test(test_bar);
    mu_run_test(test_functionToBeTested);
    return 0;
}

int main(int argc, char **argv)
{
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED!\n");
    }
    printf("Run: %d  Passed: %d  Failed: %d\n", tests_run,
           tests_run - tests_failed, tests_failed);

    return result != 0;
}

/*
cd ~/projects/HelloWorldC/tests
gcc testhelloworld.c ../bin/library.o -o ../bin/testhelloworld
*/
