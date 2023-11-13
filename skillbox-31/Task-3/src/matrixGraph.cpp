#include "matrixGraph.h"
#include <iostream>

void MatrixGraph::show() const {
    std::cout << "L | ";
    for (std::pair<int, std::unordered_set<int>> graphVertex : graphVertices){
        std::cout << graphVertex.first << " ";
    }
    std::cout << "\n";
    for (int i = 0; i < graphVertices.size() + 6; i++){
        std::cout << "_";
    }
    std::cout << "\n";
    for (std::pair<int, std::unordered_set<int>> i : graphVertices){
        std::cout << i.first << " | ";
        for (std::pair<int, std::unordered_set<int>> j : graphVertices){
            if (i.second.contains(j.first)) std::cout << "1 ";
            else std::cout << "0 ";
        }
        std::cout << "\n";
    }
}

MatrixGraph::MatrixGraph(const IGraph& graph) : IGraph(graph) {}

MatrixGraph &MatrixGraph::operator=(const IGraph &graph) {
    return *this;
}

MatrixGraph::MatrixGraph() = default;
