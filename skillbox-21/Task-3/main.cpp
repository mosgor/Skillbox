#include <iostream>
#include <numeric>
#include <limits>
#include <string>
#include <cmath>

struct math_vector{
    float x;
    float y;
};

void vector_input(math_vector& num){
    while(true){
        std::cin >> num.x >> num.y;
        if (std::cin.fail() || std::cin.peek() != '\n'){
            std::cerr << "Wrong input!\nTry again: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else break;
    }
}

void float_input(float& num){
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

math_vector vector_add(math_vector first, math_vector second){
    math_vector ans_vector = {first.x + second.x, first.y + second.y};
    return ans_vector;
}

math_vector vector_subtract(math_vector first, math_vector second){
    math_vector ans_vector = {first.x - second.x, first.y - second.y};
    return ans_vector;
}

math_vector vector_scale(math_vector first, float second){
    math_vector ans_vector = {first.x * second, first.y * second};
    return ans_vector;
}

float vector_length(math_vector firts){
    return sqrt(firts.x * firts.x + firts.y * firts.y);
}

math_vector vector_normalize(math_vector first){
    float len = vector_length(first);
    math_vector ans_vector = {first.x / len, first.y / len};
    return ans_vector;
}

int main(){
    std::cout << "Input operation: ";
    std::string operation;
    std::cin >> operation;
    if (operation == "add"){
        std::cout << "Input coordinates of first vector: ";
        math_vector first;
        vector_input(first);
        std::cout << "Input coordinates of second vector: ";
        math_vector second;
        vector_input(second);
        math_vector result = vector_add(first, second);
        std::cout << "Result of operation is " << result.x << " " << result.y;
    }
    else if (operation == "subtract"){
        std::cout << "Input coordinates of first vector: ";
        math_vector first;
        vector_input(first);
        std::cout << "Input coordinates of second vector: ";
        math_vector second;
        vector_input(second);
        math_vector result = vector_subtract(first, second);
        std::cout << "Result of operation is " << result.x << " " << result.y;
    }
    else if (operation == "scale"){
        std::cout << "Input coordinates of vector: ";
        math_vector first;
        vector_input(first);
        std::cout << "Input scalar value: ";
        float scalar;
        float_input(scalar);
        math_vector result = vector_scale(first, scalar);
        std::cout << "Result of operation is " << result.x << " " << result.y;
    }
    else if (operation == "length"){
        std::cout << "Input coordinates of vector: ";
        math_vector first;
        vector_input(first);
        float result = vector_length(first);
        std::cout << "Result of operation is " << result;
    }
    else if (operation == "normalize"){
        std::cout << "Input coordinates of vector: ";
        math_vector first;
        vector_input(first);
        math_vector result = vector_normalize(first);
        std::cout << "Result of operation is " << result.x << " " << result.y;
    }
    else std::cout << "Wrong input!";
    return 0;
}