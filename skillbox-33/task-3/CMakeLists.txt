cmake_minimum_required(VERSION 3.0)

project (DataRegistry LANGUAGES CXX VERSION 1.0)

add_executable(DataRegistry src/main.cpp include/registry.h)

target_include_directories(DataRegistry PUBLIC ${CMAKE_SOURCE_DIR}/include)