#include "disk.h"
#include "ram.h"
#include <fstream>
#include <iostream>

void save(){
    std::ofstream data("data.txt");
    if (!data.is_open()){
        std::cerr << "Error opening file!";
        exit(1);
    }
    int memory[8];
    ram_read(memory);
    for (int i : memory) data << i << " ";
    data.close();
}

void load(){
    std::ifstream data("data.txt");
    if (!data.is_open()){
        std::cerr << "Error opening file!";
        exit(1);
    }
    int new_data[8];
    for (int i = 0; i < 8; i++) data >> new_data[i];
    ram_write(new_data);
    data.close();
}