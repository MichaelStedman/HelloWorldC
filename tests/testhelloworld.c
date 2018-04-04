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
char *tests_current;
static char *test_strStrip_EmptyString()
{
    //Arrange
    char sourceString[] = "";
    char expected[] = "";

    //Act
    char *actual = strStrip(sourceString, '*');

    //Assert
    char *str = malloc(80);
    sprintf(str, "Expected |%s| Actual |%s|", expected, actual);
    Assert_AreEqual_String(expected, actual, str);

    free(str);
    str = NULL;
    free(actual);
    actual = NULL;
    return 0;
}
static char *test_strStrip_Bug1()
{
    //Arrange
    char sourceString[] = "M H*S";
    char expected[] = "M H*S";

    //Act
    char *actual = strStrip(sourceString, '*');

    //Assert
    char *str = malloc(80);
    sprintf(str, "Expected |%s| Actual |%s|", expected, actual);
    Assert_AreEqual_String(expected, actual, str);

    free(str);
    str = NULL;
    free(actual);
    actual = NULL;
    return 0;
}

static char *test_strStrip()
{
    //Arrange
    char sourceString[] = "***Michael***Henry****Stedman*****";
    char expected[] = "Michael*Henry*Stedman";

    //Act
    char *actual = strStrip(sourceString, '*');

    //Assert
    char *str = malloc(80);
    sprintf(str, "Expected |%s| Actual |%s|", expected, actual);
    Assert_AreEqual_String(expected, actual, str);

    free(str);
    str = NULL;
    free(actual);
    actual = NULL;
    return 0;
}

static char *test_strRStrip()
{
    //Arrange
    char sourceString[] = "Michael********";
    char expected[] = "Michael";

    //Act
    char *actual = strRStrip(sourceString, '*');

    //Assert
    char *str = malloc(80);
    sprintf(str, "Expected |%s| Actual |%s|", expected, actual);
    Assert_AreEqual_String(expected, actual, str);

    free(str);
    str = NULL;
    free(actual);
    actual = NULL;
    return 0;
}

static char *test_strLStrip()
{
    //Arrange
    char sourceString[] = "****Michael";
    char expected[] = "Michael";

    //Act
    char *actual = strLStrip(sourceString, '*');

    //Assert
    char *str = malloc(80);
    sprintf(str, "Expected |%s| Actual |%s|", expected, actual);
    Assert_AreEqual_String(expected, actual, str);

    free(str);
    str = NULL;
    free(actual);
    actual = NULL;
    return 0;
}

static char *test_strLTrim()
{
    //Arrange
    char sourceString[] = "   Michael";
    char expected[] = "Michael";

    //Act
    char *actual = strLTrim(sourceString);

    //Assert
    char *str = malloc(80);
    sprintf(str, "Expected |%s| Actual |%s|", expected, actual);
    Assert_AreEqual_String(expected, actual, str);

    free(str);
    str = NULL;
    free(actual);
    actual = NULL;
    return 0;
}

static char *test_strRTrim()
{
    //Arrange
    char sourceString[] = "Michael   ";
    char expected[] = "Michael";

    //Act
    char *actual = strRTrim(sourceString);

    //Assert
    char *str = malloc(80);
    sprintf(str, "Expected |%s| Actual |%s|", expected, actual);
    Assert_AreEqual_String(expected, actual, str);

    free(str);
    str = NULL;
    free(actual);
    actual = NULL;
    return 0;
}

static char *test_strMid()
{
    //Arrange
    char sourceString[] = "Michael";
    char expected[] = "cha";

    //Act
    char *actual = strMid(sourceString, 2, 3);

    //Assert
    char *str = malloc(80);
    sprintf(str, "Expected |%s| Actual |%s|", expected, actual);
    Assert_AreEqual_String(expected, actual, str);

    free(str);
    str = NULL;
    free(actual);
    actual = NULL;
    return 0;
}

static char *test_strRight()
{
    //Arrange
    char sourceString[] = "Michael";
    char expected[] = "ael";

    //Act
    char *actual = strRight(sourceString, 3);

    //Assert
    char *str = malloc(80);
    sprintf(str, "Expected |%s| Actual |%s|", expected, actual);
    Assert_AreEqual_String(expected, actual, str);

    free(str);
    str = NULL;
    free(actual);
    actual = NULL;
    return 0;

}

static char *test_strLeft()
{
    //Arrange
    char sourceString[] = "Michael";
    char expected[] = "Mic";

    //Act
    char *actual = strLeft(sourceString, 3);

    //Assert
    char *str = malloc(80);
    sprintf(str, "Expected |%s| Actual |%s|", expected, actual);
    Assert_AreEqual_String(expected, actual, str);

    free(str);
    str = NULL;
    free(actual);
    actual = NULL;
    return 0;

}

static char *test_strConcat()
{
    //Arrange
    char stringA[] = "Michael";
    char stringB[] = " ";
    char stringC[] = "Henry";
    char stringD[] = " ";
    char stringE[] = "Stedman";
    char expected[] = "Michael Henry Stedman";

    //Act
    char *actual =
        strConcat(5, stringA, stringB, stringC, stringD, stringE);

    //Assert
    char *str = malloc(80);
    sprintf(str, "Expected |%s| Actual |%s|", expected, actual);
    Assert_AreEqual_String(expected, actual, str);

    free(str);
    str = NULL;
    free(actual);
    actual = NULL;
    return 0;
}

static char *test_strStartsWith_NotFound()
{
    //Arrange
    char sourceString[] = "Mike";
    char searchString[] = "xx";
    bool expected = false;

    //Act
    bool actual = strStartsWith(sourceString, searchString);

    //Assert
    char *str = malloc(80);
    sprintf(str, "Expected %d Actual %d", expected, actual);

    Assert_AreEqual(expected, actual, str);

    free(str);
    str = NULL;

    return 0;
}

static char *test_strStartsWith_Found()
{
    //Arrange
    char sourceString[] = "Mike";
    char searchString[] = "Mi";
    bool expected = true;

    //Act
    bool actual = strStartsWith(sourceString, searchString);

    //Assert
    char *str = malloc(80);
    sprintf(str, "Expected %d Actual %d", expected, actual);

    Assert_AreEqual(expected, actual, str);

    free(str);
    str = NULL;

    return 0;
}

static char *test_strCapitalise()
{
    //Arrange
    char sourceString[] = "mike";
    char expected[] = "Mike";

    //Act
    char *actual = strCapitalise(sourceString);

    //Assert
    char *str = malloc(80);
    sprintf(str, "Expected %s Actual %s", expected, actual);
    Assert_AreEqual_String(expected, actual, str);

    free(str);
    str = NULL;
    free(actual);
    actual = NULL;

    return 0;
}

static char *test_strLower()
{
    //Arrange
    char sourceString[] = "MIKE";
    char expected[] = "mike";

    //Act
    char *actual = strLowerCase(sourceString);

    //Assert
    char *str = malloc(80);
    sprintf(str, "Expected %s Actual %s", expected, actual);
    Assert_AreEqual_String(expected, actual, str);

    free(str);
    str = NULL;
    free(actual);
    actual = NULL;

    return 0;
}

static char *test_strUpper()
{
    //Arrange
    char sourceString[] = "mike";
    char expected[] = "MIKE";

    //Act
    char *actual = strUpperCase(sourceString);

    //Assert
    char *str = malloc(80);
    sprintf(str, "Expected %s Actual %s", expected, actual);
    Assert_AreEqual_String(expected, actual, str);

    free(str);
    str = NULL;
    free(actual);
    actual = NULL;

    return 0;
}

static char *test_strIndex()
{
    //Arrange
    char sourceString[] = "abcdefg";
    char searchCharacter = 'd';
    int expected = 3;

    //Act
    int actual = strIndex(sourceString, searchCharacter, 1);

    //Assert
    char *str = malloc(80);
    sprintf(str, "Expected %d Actual %d", expected, actual);

    Assert_AreEqual(expected, actual, str);

    free(str);
    return 0;
}

static char *test_strIndex_FindSecondOccurrence()
{
    //Arrange
    char sourceString[] = "abcdefgabcdefg";
    char searchCharacter = 'd';
    int expected = 10;

    //Act
    int actual = strIndex(sourceString, searchCharacter, 2);

    //Assert
    char *str = malloc(80);
    sprintf(str, "Expected %d Actual %d", expected, actual);

    Assert_AreEqual(expected, actual, str);

    free(str);
    return 0;
}

static char *test_strIndex_MissingOccurrence()
{
    //Arrange
    char sourceString[] = "abcdefgabcdefg";
    char searchCharacter = 'd';
    int expected = -1;

    //Act
    int actual = strIndex(sourceString, searchCharacter, 99);

    //Assert
    char *str = malloc(80);
    sprintf(str, "Expected %d Actual %d", expected, actual);

    Assert_AreEqual(expected, actual, str);

    free(str);
    return 0;
}

static char *all_tests()
{
    tests_current = malloc(100);
    mu_run_test("test_strStrip_EmptyString", test_strStrip_EmptyString);
    mu_run_test("test_strStrip_Bug1", test_strStrip_Bug1);
    mu_run_test("test_strStrip", test_strStrip);
    mu_run_test("test_strRStrip", test_strRStrip);
    mu_run_test("test_strLStrip", test_strLStrip);
    mu_run_test("test_strLTrim", test_strLTrim);
    mu_run_test("test_strRTrim", test_strRTrim);
    mu_run_test("test_strMid", test_strMid);
    mu_run_test("test_strRight", test_strRight);
    mu_run_test("test_strLeft", test_strLeft);
    mu_run_test("test_strConcat", test_strConcat);
    mu_run_test("test_strStartsWith_NotFound",
                test_strStartsWith_NotFound);
    mu_run_test("test_strStartsWith_Found", test_strStartsWith_Found);
    mu_run_test("test_strCapitalise", test_strCapitalise);
    mu_run_test("test_strLower", test_strLower);
    mu_run_test("test_strUpper", test_strUpper);
    mu_run_test("test_strIndex", test_strIndex);
    mu_run_test("test_strIndex_FindSecondOccurrence",
                test_strIndex_FindSecondOccurrence);
    mu_run_test("test_strIndex_MissingOccurrence",
                test_strIndex_MissingOccurrence);
    free(tests_current);
    tests_current = NULL;
    return 0;
}

void print_highlight(bool pass)
{
    char pass_highlight[] = "\033[0;32m";       //Green
    char fail_highlight[] = "\033[0;31m";       //Red
    char *highlight = pass ? pass_highlight : fail_highlight;
    printf("%s", highlight);
}

void print_result_highlight()
{
    char bold_yellow[] = "\033[1;33m";
    printf("%s", bold_yellow);
}

void print_reset()
{
    printf("\033[0m");
}

int main(int argc, char **argv)
{
    char *result = all_tests();
    bool passOrFail = tests_failed == 0;

    print_highlight(passOrFail);
    printf("--------------------------------------\n");

    if (result != 0) {
        print_result_highlight();
        printf("%s: %s\n", tests_current, result);
    } else {
        printf("ALL TESTS PASSED!\n");
    }

    print_highlight(passOrFail);
    printf("Run: %d  Passed: %d  Failed: %d\n", tests_run,
           tests_run - tests_failed, tests_failed);
    printf("--------------------------------------\n");


    print_reset();

    return result != 0;
}

/*
Terminal Colours
================
         foreground background
black        30         40
red          31         41
green        32         42
yellow       33         43
blue         34         44
magenta      35         45
cyan         36         46
white        37         47

reset             0  (everything back to normal)
bold/bright       1  (often a brighter shade of the same colour)
underline         4
inverse           7  (swap foreground and background colours)
bold/bright off  21
underline off    24
inverse off      27
*/

/*
cd ~/projects/HelloWorldC/tests
gcc testhelloworld.c ../bin/library.o -o ../bin/testhelloworld
*/
