cmake_minimum_required(VERSION 3.0.0)

set(POINT ${CMAKE_SOURCE_DIR}/include/point.h)
set(OPERATIONS ${CMAKE_SOURCE_DIR}/include/operations.h)

add_executable(SurgeonSimulator main.cpp point.cpp operations.cpp ${POINT} ${OPERATIONS})
target_include_directories(SurgeonSimulator PUBLIC ${CMAKE_SOURCE_DIR}/include)