# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "C:/Program Files/Raspberry Pi/Pico SDK v1.5.1/pico-sdk")

set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.4.0")
  message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.4.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

project(sample_app C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(sample_app 
    main.cpp
)

pico_set_program_name(sample_app "sample_app")
pico_set_program_version(sample_app "0.1")

pico_enable_stdio_uart(sample_app 0)
pico_enable_stdio_usb(sample_app 1)

# Add the standard library to the build
target_link_libraries(sample_app
    pico_stdlib
)

# Add the standard include files to the build
target_include_directories(sample_app PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts or any other standard includes, if required
)

# Add any user requested libraries
target_link_libraries(sample_app 
    hardware_timer
)

pico_add_extra_outputs(sample_app)

add_subdirectory(blink)
target_include_directories(sample_app PRIVATE 
    blink
)
target_link_libraries(sample_app 
    blink
)

# FreeRTOS
add_subdirectory(freertos)
target_include_directories(sample_app PRIVATE 
    freertos
    freertos/FreeRTOS-Kernel/include
    freertos/FreeRTOS-Kernel/portable/GCC/ARM_CM0
)
target_link_libraries(sample_app
    freertos
)