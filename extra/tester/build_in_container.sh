#!/bin/bash

cd /build
cmake /src -DTESTING=1
make
VALGRIND=y ./test_runner
gcov -mpc $(find . -name \*.o)
gcovr -r /src . > gcovr-summary.txt
gcovr -r /src . --json > gcovr-full.json
cp --parents $(find . -name \*.gcov) /results
cp valgrind-result.xml gcovr-summary.txt gcovr-full.json /results
