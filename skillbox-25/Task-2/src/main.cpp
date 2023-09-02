#include <iostream>
#include <string>
#include "disk.h"
#include "gpu.h"
#include "kbd.h"
#include "cpu.h"

int main(){
    std::string command;
    while(true){
        std::cout << "Input command: ";
        std::cin >> command;
        if (command == "sum") compute();
        else if (command == "save") save();
        else if (command == "load") load();
        else if (command == "input") input();
        else if (command == "display") display();
        else if (command == "exit") break;
        else std::cout << "Wrong input!\n"; 
    }
    return 0;
}