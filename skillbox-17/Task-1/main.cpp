#include <iostream>
#include<limits>
#include<numeric>

void swap(int* a, int* b){
    int temporary = *a;
    *a = *b;
    *b = temporary;
}

void input(int* value)
{
    while(true){
        std::cin >> *value;
        if (std::cin.fail() || std::cin.peek() != '\n'){
            std::cerr << "Wrong input, try again!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else break;
    }
}

main(){
    std::cout << "Input first number: ";
    int first, second;
    input(&first);
    std::cout << "Input second number: ";
    input(&second);
    swap(&first, &second);
    std::cout << "Switched numbers: " << first << " " << second;
    return 0;
}