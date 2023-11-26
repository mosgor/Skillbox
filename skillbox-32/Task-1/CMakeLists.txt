cmake_minimum_required(VERSION 3.0)

project(Movie VERSION 1.0)

add_executable(Movie src/main.cpp)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

target_link_libraries(Movie PRIVATE nlohmann_json::nlohmann_json)