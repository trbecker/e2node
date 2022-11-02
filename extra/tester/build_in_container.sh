#!/bin/bash

cd /build
cmake /src -DTESTING=1
make
./test_runner
