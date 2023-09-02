cmake_minimum_required(VERSION 3.0.0)

project(ComputerSimulator VERSION 1.0)

set(CPU ${CMAKE_SOURCE_DIR}/include/cpu.h)
set(DISK ${CMAKE_SOURCE_DIR}/include/disk.h)
set(GPU ${CMAKE_SOURCE_DIR}/include/gpu.h)
set(KBD ${CMAKE_SOURCE_DIR}/include/kbd.h)
set(RAM ${CMAKE_SOURCE_DIR}/include/ram.h)

add_subdirectory(src)