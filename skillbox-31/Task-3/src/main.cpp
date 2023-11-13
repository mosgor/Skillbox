#include <iostream>
#include "listGraph.h"
#include "matrixGraph.h"

int main(){
    ListGraph a;
    a.addEdge(5, 6);
    a.addEdge(7, 5);
    a.addEdge(5, 7);
    std::cout << a.verticesCount() << "\n";
    a.show();
    std::cout << "\n";
    MatrixGraph b(a);
    ListGraph c = b;
    b.show();
    std::cout << "\n";
    c.show();
    std::vector<int> abc;
    c.getPrevVertices(5, abc);
    for (int x : abc){
        std::cout << x << " ";
    }
    std::cout << "\n";
    abc.clear();
    c.getNextVertices(5, abc);
    for (int x : abc){
        std::cout << x << " ";
    }
    return 0;
}