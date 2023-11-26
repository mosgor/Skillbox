cmake_minimum_required(VERSION 3.0)

project(MovieAnalyzer VERSION 1.0)

add_executable(MovieAnalyzer src/main.cpp src/movie.cpp include/movie.h)

target_include_directories(MovieAnalyzer PUBLIC ${CMAKE_SOURCE_DIR}/include)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

target_link_libraries(MovieAnalyzer PRIVATE nlohmann_json::nlohmann_json)