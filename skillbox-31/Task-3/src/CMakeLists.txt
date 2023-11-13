cmake_minimum_required(VERSION 3.0)

add_executable(Graphs main.cpp igraph.cpp listGraph.cpp matrixGraph.cpp ${IGRAPH} ${LISTGRAPH} ${MATRIXGRAPH})

target_include_directories(Graphs PUBLIC ${CMAKE_SOURCE_DIR}/include)