#include <iostream>
#include <sstream>
#include <string>

main(){
    while(true){
        std::string temp = "";
        std::cout << "Input comand: ";
        std::getline(std::cin, temp);
        double first = 0, second = 0;
        char operation;
        std::stringstream temp_stream(temp);
        temp_stream >> first >> operation >> second;
        std::cout << "Result: ";
        switch (operation)
        {
        case '+':
            std::cout << first + second << "\n";
            break;
        case '-':
            std::cout << first - second << "\n";
            break;
        case '*':
            std::cout << first * second << "\n";
            break;
        case '/':
            std::cout << first / second << "\n";
            break;
        default:
            std::cout << "Wrong operation!\n";
            break;
        }
    }
}