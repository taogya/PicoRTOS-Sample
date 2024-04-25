#!/bin/bash

rm -rf src/build
cmake -S src -B src/build -G Ninja
cmake --build src/build
