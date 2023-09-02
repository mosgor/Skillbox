cmake_minimum_required(VERSION 3.0.0)

add_executable(ComputerSimulator main.cpp cpu.cpp disk.cpp gpu.cpp kbd.cpp ram.cpp ${CPU} ${DISK} ${GPU} ${KBD} ${RAM})

target_include_directories(ComputerSimulator PUBLIC ${CMAKE_SOURCE_DIR}/include)