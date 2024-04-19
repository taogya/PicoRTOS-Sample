cmake_minimum_required(VERSION 3.13)

set(FREERTOS_KERNEL_PATH ${CMAKE_CURRENT_LIST_DIR}/FreeRTOS-Kernel)
add_library(freertos
    ${FREERTOS_KERNEL_PATH}/portable/GCC/ARM_CM0/portasm.c
)
include(FreeRTOS_Kernel_import.cmake)
target_include_directories(freertos PUBLIC
    ./
    # ${FREERTOS_KERNEL_PATH}/portable/GCC/ARM_CM0
    ${FREERTOS_KERNEL_PATH}/portable/ThirdParty/GCC/RP2040/include
)
target_link_libraries(freertos
    FreeRTOS-Kernel
    FreeRTOS-Kernel-Heap3
    pico_stdlib
)