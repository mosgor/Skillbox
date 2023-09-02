#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::string goal;
    std::cout << "Input kind of fish you want to catch: ";
    std::cin >> goal;
    std::ifstream river("river.txt");
    std::ofstream basket("basket.txt", std::ios::app);
    int counter = 0;
    while (!river.eof()){
        std::string temp;
        river >> temp;
        if (temp == goal) {
            basket << temp << std::endl;
            counter++;
        }
    }
    river.close();
    basket.close();
    std::cout << "You cached " << counter << " fishes";
    return 0;
}