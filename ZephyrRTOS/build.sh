#!/bin/bash

SOURCE_PATH="$(pwd)"/src
BUILD_PATH="$(pwd)"/build
CUSTOM_BOARD=boards/raspberrypi/rpi_pico_custom
ZEPHYR_PRJ_PATH="$HOME"/zephyrproject
VENV_PATH="$ZEPHYR_PRJ_PATH"/.venv

. "$VENV_PATH"/bin/activate

if [ "$1" == "clean" ]; then
    rm -rf "$BUILD_PATH"
    exit 0
fi

rm -rf "$ZEPHYR_PRJ_PATH"/zephyr/"$CUSTOM_BOARD"
cp -r "$SOURCE_PATH"/"$CUSTOM_BOARD" "$ZEPHYR_PRJ_PATH"/zephyr/"$CUSTOM_BOARD"
pushd "$ZEPHYR_PRJ_PATH"
west build -b rpi_pico_custom -s "$SOURCE_PATH" -d "$BUILD_PATH"
popd
deactivate