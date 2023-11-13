cmake_minimum_required(VERSION 3.0.0)

project(Graphs VERSION 1.0)

set(IGRAPH ${CMAKE_SOURCE_DIR}/include/igraph.h)
set(LISTGRAPH ${CMAKE_SOURCE_DIR}/include/listGraph.h)
set(MATRIXGRAPH ${CMAKE_SOURCE_DIR}/include/matrixGraph.h)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src)