#pragma once
#include "igraph.h"
#include "listGraph.h"

class MatrixGraph: public IGraph{
public:
    void show() const override;

    MatrixGraph();

    MatrixGraph(const IGraph& graph);

    MatrixGraph& operator=(const IGraph& graph);
};