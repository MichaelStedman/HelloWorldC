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
static char *test_strMid(){
    //Arrange
    char sourceString[] = "Michael";
    char expected[] = "cha";

    //Act
    char *actual = strMid(sourceString, 2, 3);

    //Assert
    char *str = malloc(80);
    sprintf(str, "Expected |%s| Actual |%s|", expected, actual);

    Assert_AreEqual(expected[0], actual[0], str);

    free(str);
    str = NULL;
    free(actual);
    actual = NULL;
    return 0;
    
}

static char *test_strRight(){
    //Arrange
    char sourceString[] = "Michael";
    char expected[] = "ael";

    //Act
    char *actual = strRight(sourceString, 3);

    //Assert
    char *str = malloc(80);
    sprintf(str, "Expected |%s| Actual |%s|", expected, actual);

    Assert_AreEqual(expected[0], actual[0], str);

    free(str);
    str = NULL;
    free(actual);
    actual = NULL;
    return 0;
    
}
static char *test_strLeft(){
    //Arrange
    char sourceString[] = "Michael";
    char expected[] = "Mic";

    //Act
    char *actual = strLeft(sourceString, 3);

    //Assert
    char *str = malloc(80);
    sprintf(str, "Expected |%s| Actual |%s|", expected, actual);

    Assert_AreEqual(expected[0], actual[0], str);

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
    char *actual = strConcat(5, stringA, stringB, stringC, stringD, stringE);

    //Assert
    char *str = malloc(80);
    sprintf(str, "Expected |%s| Actual |%s|", expected, actual);

    Assert_AreEqual(expected[0], actual[0], str);

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
    char *str3 = malloc(80);
    sprintf(str3, "Expected %s Actual %s", expected, actual);

    Assert_AreEqual(expected[0], actual[0], str3);

    free(str3);
    str3 = NULL;
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
    char *str3 = malloc(80);
    sprintf(str3, "Expected %s Actual %s", expected, actual);

    Assert_AreEqual(expected[0], actual[0], str3);

    free(str3);
    str3 = NULL;
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
    char *str3 = malloc(80);
    sprintf(str3, "Expected %s Actual %s", expected, actual);

    Assert_AreEqual(expected[0], actual[0], str3);

    free(str3);
    str3 = NULL;
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
    char *str3 = malloc(80);
    sprintf(str3, "Expected %d Actual %d", expected, actual);

    Assert_AreEqual(expected, actual, str3);

    free(str3);
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
    char *str3 = malloc(80);
    sprintf(str3, "Expected %d Actual %d", expected, actual);

    Assert_AreEqual(expected, actual, str3);

    free(str3);
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
    char *str3 = malloc(80);
    sprintf(str3, "Expected %d Actual %d", expected, actual);

    Assert_AreEqual(expected, actual, str3);

    free(str3);
    return 0;
}

static char *all_tests()
{
    mu_run_test(test_strMid);
    mu_run_test(test_strRight);
    mu_run_test(test_strLeft);
    mu_run_test(test_strConcat);
    mu_run_test(test_strStartsWith_NotFound);
    mu_run_test(test_strStartsWith_Found);
    mu_run_test(test_strCapitalise);
    mu_run_test(test_strLower);
    mu_run_test(test_strUpper);
    mu_run_test(test_strIndex);
    mu_run_test(test_strIndex_FindSecondOccurrence);
    mu_run_test(test_strIndex_MissingOccurrence);
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
