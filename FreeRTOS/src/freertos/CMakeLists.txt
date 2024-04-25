cmake_minimum_required(VERSION 3.13)

set(FREERTOS_KERNEL_PATH ${CMAKE_CURRENT_LIST_DIR}/FreeRTOS-Kernel)
add_subdirectory(${FREERTOS_KERNEL_PATH}/portable/ThirdParty/GCC/RP2040 FreeRTOS-Kernel)
add_library(freertos INTERFACE
)
target_include_directories(freertos INTERFACE
    ./
)
target_link_libraries(freertos INTERFACE
    FreeRTOS-Kernel
    FreeRTOS-Kernel-Heap3
)