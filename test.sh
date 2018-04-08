#!/bin/sh
echo "1"
cd ~/projects/HelloWorldC/src
declare -x VERSION_CONTROL=none ; indent -kr --no-tabs *.c
echo "2"
cd ~/projects/HelloWorldC/src/include
indent -kr --no-tabs *.h
echo "3"
cd ~/projects/HelloWorldC/tests
indent -kr --no-tabs *.c
echo "4"
cd ~/projects/HelloWorldC/tests/include
indent -kr --no-tabs *.h
echo "5"
cd ~/projects/HelloWorldC/
make test
