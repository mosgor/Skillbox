#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::cout << "Input the word you want to count: ";
    std::string desired_word;
    std::cin >> desired_word;
    int counter = 0;
    std::ifstream words;
    words.open("D:\\Projects\\C++\\skillbox-19\\Task-1\\words.txt");
    while (!words.eof()){
        std::string word;
        words >> word;
        if (word == desired_word) counter++;
    }
    words.close();
    std::cout << "Count of words is: " << counter;
    return 0;
}