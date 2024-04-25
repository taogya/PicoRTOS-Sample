#!/bin/bash

SOURCE_PATH="$(pwd)"/src
BUILD_PATH="$(pwd)"/build
ZEPHYR_PRJ_PATH="$HOME"/zephyrproject
VENV_PATH="$ZEPHYR_PRJ_PATH"/.venv

. "$VENV_PATH"/bin/activate

if [ "$1" == "clean" ]; then
    rm -rf "$BUILD_PATH"
    exit 0
fi

pushd "$ZEPHYR_PRJ_PATH"
west build -b rpi_pico -s "$SOURCE_PATH" -d "$BUILD_PATH"
popd
deactivate