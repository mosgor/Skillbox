#pragma once
#include <map>
#include <unordered_set>
#include <vector>

class IGraph{
protected:
    std::map<int, std::unordered_set<int>> graphVertices;
public:
    virtual ~IGraph();
    IGraph(IGraph *_oth);
    IGraph();
    virtual void addEdge(int from, int to);
    virtual int verticesCount() const;
    virtual void getNextVertices(int vertex, std::vector<int> &vertices) const;
    virtual void getPrevVertices(int vertex, std::vector<int> &vertices) const;
    virtual void show() const = 0;
};