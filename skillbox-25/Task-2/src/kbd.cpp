#include "kbd.h"
#include "ram.h"
#include <numeric>
#include <limits>
#include <iostream>

void int_input(int& num){
    while(true){
        std::cin >> num;
        if (std::cin.fail() || std::cin.peek() != '\n'){
            std::cerr << "Wrong input!\nTry again: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else break;
    }
}

void input(){
    int new_data[8];
    for (int i = 0; i < 8; i++){
        std::cout << "Input " << i + 1 << " number: ";
        int_input(new_data[i]);
    }
    ram_write(new_data);
}