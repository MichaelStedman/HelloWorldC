/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/
#define mu_run_test(name, test) do { char *message = test(); tests_run++; \
                                if (message) {strcpy(tests_current, name); return message;} } while (0)

#define Assert_AreEqual(expected, actual, message) do { if (expected != actual) { tests_failed++; return message; } } while (0)
#define Assert_AreNotEqual(expected, actual, message) do { if (expected == actual) { tests_failed++; return message; } } while (0)

extern int tests_failed;
extern int tests_run;
extern char *tests_current;