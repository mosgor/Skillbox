#include "cpu.h"
#include "ram.h"
#include <iostream>

void compute(){
    int memory[8];
    ram_read(memory);
    int sum = 0;
    for (int i : memory) sum += i;
    std::cout << "Sum of numbers in RAM: " << sum << std::endl;
}