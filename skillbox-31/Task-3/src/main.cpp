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
    return 0;
}