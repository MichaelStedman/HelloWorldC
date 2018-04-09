/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/minunit.h"
#include "../src/include/library.h"

/*
MU_TEST(test_strStrToInt)
{
    //Arrange
    char sourceString[] = "1234567";
    int expected = 1234567;

    //Act
    int actual = strStrToInt(sourceString);

    //Assert
    mu_assert_int_eq(expected, actual);
}

MU_TEST(test_strIntToStr)
{
    //Arrange
    int value = 1234567;
    char expected[] = "1234567";

    //Act
    char *actual = strIntToStr(value);

    //Assert
    mu_assert_string_eq(expected, actual);

    free(actual);
}
*/
MU_TEST(test_strLPad_SourceLengthExceedsLength)
{
    //Arrange
    char sourceString[] = "MikeStedman";
    char expected[] = "Mike";
    int length = strlen(expected);

    //Act
    char *actual = strLPad(sourceString, '*', length);

    //Assert
    mu_assert_string_eq(expected, actual);

    free(actual);
}

MU_TEST(test_strLPad)
{
    //Arrange
    char sourceString[] = "Mike";
    char expected[] = "*****Mike";
    int length = strlen(expected);

    //Act
    char *actual = strLPad(sourceString, '*', length);

    //Assert
    mu_assert_string_eq(expected, actual);

    free(actual);
}

MU_TEST(test_strRPad)
{
    //Arrange
    char sourceString[] = "Mike";
    char expected[] = "Mike*****";
    int length = strlen(expected);

    //Act
    char *actual = strRPad(sourceString, '*', length);

    //Assert
    mu_assert_string_eq(expected, actual);

    free(actual);
}

MU_TEST(test_strStrip_EmptyString)
{
    //Arrange
    char sourceString[] = "";
    char expected[] = "";

    //Act
    char *actual = strStrip(sourceString, '*');

    //Assert
    mu_assert_string_eq(expected, actual);

    free(actual);
}

MU_TEST(test_strStrip_Bug1)
{
    //Arrange
    char sourceString[] = "M H*S";
    char expected[] = "M H*S";

    //Act
    char *actual = strStrip(sourceString, '*');

    //Assert
    mu_assert_string_eq(expected, actual);

    free(actual);
}

MU_TEST(test_strStrip)
{
    //Arrange
    char sourceString[] = "***Michael***Henry****Stedman*****";
    char expected[] = "Michael*Henry*Stedman";

    //Act
    char *actual = strStrip(sourceString, '*');

    //Assert
    mu_assert_string_eq(expected, actual);

    free(actual);
}

MU_TEST(test_strRStrip)
{
    //Arrange
    char sourceString[] = "Michael********";
    char expected[] = "Michael";

    //Act
    char *actual = strRStrip(sourceString, '*');

    //Assert
    mu_assert_string_eq(expected, actual);

    free(actual);
}

MU_TEST(test_strLStrip)
{
    //Arrange
    char sourceString[] = "****Michael";
    char expected[] = "Michael";

    //Act
    char *actual = strLStrip(sourceString, '*');

    //Assert
    mu_assert_string_eq(expected, actual);

    free(actual);
}

MU_TEST(test_strLTrim)
{
    //Arrange
    char sourceString[] = "   Michael";
    char expected[] = "Michael";

    //Act
    char *actual = strLTrim(sourceString);

    //Assert
    mu_assert_string_eq(expected, actual);

    free(actual);
}

MU_TEST(test_strRTrim)
{
    //Arrange
    char sourceString[] = "Michael   ";
    char expected[] = "Michael";

    //Act
    char *actual = strRTrim(sourceString);

    //Assert
    mu_assert_string_eq(expected, actual);

    free(actual);
}

MU_TEST(test_strMid)
{
    //Arrange
    char sourceString[] = "Michael";
    char expected[] = "cha";

    //Act
    char *actual = strMid(sourceString, 2, 3);

    //Assert
    mu_assert_string_eq(expected, actual);

    free(actual);
}

MU_TEST(test_strRight)
{
    //Arrange
    char sourceString[] = "Michael";
    char expected[] = "ael";

    //Act
    char *actual = strRight(sourceString, 3);

    //Assert
    mu_assert_string_eq(expected, actual);

    free(actual);
}

MU_TEST(test_strLeft)
{
    //Arrange
    char sourceString[] = "Michael";
    char expected[] = "Mic";

    //Act
    char *actual = strLeft(sourceString, 3);

    //Assert
    mu_assert_string_eq(expected, actual);

    free(actual);
}

MU_TEST(test_strConcat)
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
    mu_assert_string_eq(expected, actual);

    free(actual);
}

MU_TEST(test_strStartsWith_NotFound)
{
    //Arrange
    char sourceString[] = "Mike";
    char searchString[] = "xx";
    bool expected = false;

    //Act
    bool actual = strStartsWith(sourceString, searchString);

    //Assert
    mu_assert_int_eq(expected, actual);
}

MU_TEST(test_strStartsWith_Found)
{
    //Arrange
    char sourceString[] = "Mike";
    char searchString[] = "Mi";
    bool expected = true;

    //Act
    bool actual = strStartsWith(sourceString, searchString);

    //Assert
    mu_assert_int_eq(expected, actual);
}

MU_TEST(test_strCapitalise)
{
    //Arrange
    char sourceString[] = "mike";
    char expected[] = "Mike";

    //Act
    char *actual = strCapitalise(sourceString);

    //Assert
    mu_assert_string_eq(expected, actual);

    free(actual);
}

MU_TEST(test_strLower)
{
    //Arrange
    char sourceString[] = "MIKE";
    char expected[] = "mike";

    //Act
    char *actual = strLowerCase(sourceString);

    //Assert
    mu_assert_string_eq(expected, actual);

    free(actual);
}

MU_TEST(test_strUpper)
{
    //Arrange
    char sourceString[] = "mike";
    char expected[] = "MIKE";

    //Act
    char *actual = strUpperCase(sourceString);

    //Assert
    mu_assert_string_eq(expected, actual);

    free(actual);
}

MU_TEST(test_strIndex)
{
    //Arrange
    char sourceString[] = "abcdefg";
    char searchCharacter = 'd';
    int expected = 3;

    //Act
    int actual = strIndex(sourceString, searchCharacter, 1);

    //Assert
    mu_assert_int_eq(expected, actual);
}

MU_TEST(test_strIndex_FindSecondOccurrence)
{
    //Arrange
    char sourceString[] = "abcdefgabcdefg";
    char searchCharacter = 'd';
    int expected = 10;

    //Act
    int actual = strIndex(sourceString, searchCharacter, 2);

    //Assert
    mu_assert_int_eq(expected, actual);
}

MU_TEST(test_strIndex_MissingOccurrence)
{
    //Arrange
    char sourceString[] = "abcdefgabcdefg";
    char searchCharacter = 'd';
    int expected = -1;

    //Act
    int actual = strIndex(sourceString, searchCharacter, 99);

    //Assert
    mu_assert_int_eq(expected, actual);
}

MU_TEST_SUITE(test_suite)
{
    //mu_run_test("test_strStrToInt", test_strStrToInt);
    //mu_run_test("test_strIntToStr", test_strIntToStr);
    MU_RUN_TEST(test_strLPad_SourceLengthExceedsLength);
    MU_RUN_TEST(test_strRPad);
    MU_RUN_TEST(test_strLPad);
    MU_RUN_TEST(test_strStrip_EmptyString);
    MU_RUN_TEST(test_strStrip_Bug1);
    MU_RUN_TEST(test_strStrip);
    MU_RUN_TEST(test_strRStrip);
    MU_RUN_TEST(test_strLStrip);
    MU_RUN_TEST(test_strLTrim);
    MU_RUN_TEST(test_strRTrim);
    MU_RUN_TEST(test_strMid);
    MU_RUN_TEST(test_strRight);
    MU_RUN_TEST(test_strLeft);
    MU_RUN_TEST(test_strConcat);
    MU_RUN_TEST(test_strStartsWith_NotFound);
    MU_RUN_TEST(test_strStartsWith_Found);
    MU_RUN_TEST(test_strCapitalise);
    MU_RUN_TEST(test_strLower);
    MU_RUN_TEST(test_strUpper);
    MU_RUN_TEST(test_strIndex);
    MU_RUN_TEST(test_strIndex_FindSecondOccurrence);
    MU_RUN_TEST(test_strIndex_MissingOccurrence);
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
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return 0;
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
