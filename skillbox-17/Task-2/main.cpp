#include <iostream>
#include <limits>
#include <numeric>

void input(int* value){
    while(true){
        std::cin >> *value;
        if (std::cin.fail() || std::cin.peek() != '\n'){
            std::cerr << "Wrong input. Try again!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else break;
    }
}

void reverse(int* arr){
    for (int i = 0; i < 5; i++){
        int temp = *(arr + 9 - i);
        *(arr + 9 - i) = *(arr + i);
        *(arr + i) = temp;
    }
}

main(){
    std::cout << "Input ten numbers: ";
    int array[10];
    for (int i = 0; i < 10; i++){
        int temp;
        input(&temp);
        array[i] = temp;
    }
    reverse(array);
    std::cout << "Reversed array: ";
    for (int i : array){
        std::cout << i << " ";
    }
    return 0;
}