#!/bin/bash
set -e

mkdir -p ./out

cd out

cmake .. -DCMAKE_BUILD_TYPE=RELEASE
make

./member_init
