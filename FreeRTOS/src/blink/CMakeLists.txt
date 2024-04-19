# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

add_library(blink
    STATIC
    blink.cpp
)

target_link_libraries(blink
    pico_stdlib
)