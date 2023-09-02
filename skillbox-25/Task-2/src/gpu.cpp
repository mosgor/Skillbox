#include "gpu.h"
#include "ram.h"
#include <iostream>

void display(){
    std::cout << "RAM: ";
    int memory[8];
    ram_read(memory);
    for (int i : memory) std::cout << i << " ";
    std::cout << "\n";
}