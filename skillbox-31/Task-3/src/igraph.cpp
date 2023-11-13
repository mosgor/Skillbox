#include "igraph.h"
#include <iostream>

IGraph::IGraph(IGraph *_oth) {
    graphVertices = _oth->graphVertices;
}

int IGraph::verticesCount() const {
    return graphVertices.size();
}

void IGraph::getNextVertices(int vertex, std::vector<int> &vertices) const {
    if (graphVertices.count(vertex) == 0){
        std::cout << "There is no such vertex!\n";
        return;
    }
    vertices.insert(vertices.begin(), graphVertices.at(vertex).begin(), graphVertices.at(vertex).end());
}

void IGraph::getPrevVertices(int vertex, std::vector<int> &vertices) const {
    if (graphVertices.count(vertex) == 0){
        std::cout << "There is no such vertex!\n";
        return;
    }
    for (std::pair<int, std::unordered_set<int>> graphVertex : graphVertices){
        if (graphVertex.second.contains(vertex)){
            vertices.push_back(graphVertex.first);
        }
    }
}

void IGraph::addEdge(int from, int to) {
    graphVertices[from].insert(to);
    graphVertices[to];
}

IGraph::IGraph() = default;

IGraph::~IGraph() = default;