#include <iostream>
#include <string>
#include "registry.h"

int main(){
    Registry<std::string, int> reg;
    reg.add("a", 5);
    reg.add("a", 6);
    reg.add("v", 2);
    reg.print();
    for (int a : reg.find("a")){
        std::cout << a << " ";
    }
    std::cout << std::endl;
    reg.remove("a");
    reg.print();
}