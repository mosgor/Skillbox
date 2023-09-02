#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>

void correct_numbers(int& number, std::string object){
    while(true){
        std::cout << "Input " << object << " of picture: ";
        std::cin >> number;
        if (number > 0) break;
        std::cout << "Wrong input!\n";
    }
}

int main(){
    std::srand(std::time(nullptr));
    int width, height;
    correct_numbers(width, "width");
    correct_numbers(height, "height");
    std::ofstream picture("pic.txt");
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            picture << std::rand() % 2;
        }
        picture << std::endl;
    }
    picture.close();
    return 0;
}