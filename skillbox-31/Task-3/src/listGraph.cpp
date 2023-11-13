#include "listGraph.h"
#include <iostream>

void ListGraph::show() const {
    for(auto i = graphVertices.begin(); i != graphVertices.end(); i++){
        std::cout << i->first;
        std::string s = "->";
        for (auto j : i->second){
            s += std::to_string(j) + "->";
        }
        std::cout << s.substr(0, s.size() - 2) << "\n";
    }
}

ListGraph::ListGraph(const IGraph& graph) : IGraph(graph) {}

ListGraph &ListGraph::operator=(const IGraph &graph) {
    return *this;
}

ListGraph::ListGraph() = default;
