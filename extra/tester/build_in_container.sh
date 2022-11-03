#!/bin/bash

cd /build
cmake /src -DTESTING=1
make
VALGRIND=y ./test_runner
gcov -mpc $(find . -name \*.o)
cp --parents $(find . -name \*.gcov) /results
