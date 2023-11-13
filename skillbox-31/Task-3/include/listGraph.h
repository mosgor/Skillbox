#pragma once
#include "igraph.h"
#include "matrixGraph.h"

class ListGraph: public IGraph{
public:
    void show() const override;

    ListGraph();

    ListGraph(const IGraph& graph);

    ListGraph& operator=(const IGraph& graph);
};