#include <iostream>
#include <string>

int main(){
    std::string str_form = "";
    std::cout << "Input part of number before point: ";
    int input;
    std::cin >> input;
    str_form += std::to_string(input) + '.';
    std::cout << "Input part of number after point: ";
    std::cin >> input;
    str_form += std::to_string(input);
    double result = stod(str_form);
    std::cout << "Your number " << result;
    return 0;
}