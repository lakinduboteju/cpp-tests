#!/bin/bash
set -e

mkdir -p ./out

cd out

cmake .. -DCMAKE_BUILD_TYPE=RELEASE
make

./object_alloc

./object_alloc_test
