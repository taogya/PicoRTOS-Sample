#!/bin/bash

SOURCE_PATH=$(pwd)/src
BUILD_PATH=$(pwd)/build

if [ "$1" == "clean" ]; then
    rm -rf "$BUILD_PATH"
    exit 0
fi

cmake -S "$SOURCE_PATH" -B "$BUILD_PATH" -G Ninja
cmake --build "$BUILD_PATH"
