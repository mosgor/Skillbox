cmake_minimum_required(VERSION 3.0)

project(Requests VERSION 1.0)

add_executable(Requests src/main.cpp)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG 3b15fa8)
FetchContent_MakeAvailable(cpr)

target_link_libraries(Requests PRIVATE cpr::cpr)