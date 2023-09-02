#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <numeric>
#include <vector>
#include <cstdlib>
#include <ctime>

void int_input(int& num){
    while(true){
        std::cin >> num;
        if (std::cin.fail() || std::cin.peek() != '\n' || num % 100 != 0){
            std::cerr << "Wrong input!\nTry again: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else break;
    }
}

void export_to_file(std::vector<int>& atm){
    std::ofstream file("ATM.bin", std::ios::binary);
    for (int i : atm){
        file.write((char*)&i, sizeof(i));
    }
    file.close();
}

void import_from_file(std::vector<int>& atm){
    std::ifstream file("ATM.bin", std::ios::binary);
    for (int i = 0; i < 1000; i++){
        file.read((char *)& atm[i], sizeof(int));
    }
    file.close();
}

void add_money(std::vector<int>& atm){
    int banknotes[] = {100, 200, 500, 1000, 2000, 5000};
    for (int i = 0; i < 1000; i++){    
        if (atm[i] == 0){
            int temporary = std::rand() % 6;
            atm[i] = banknotes[temporary];
        }
    }
    export_to_file(atm);
}

void withdraw_money(std::vector<int>& atm, int sum){
    int temporary = 0;
    for (int i = 0; i < 1000; i++){
        if (atm[i] != 0 && temporary + atm[i] <= sum){
            temporary += atm[i];
            atm[i] = 0;
            if (temporary == sum){
                std::cout << "Here's your money!";
                export_to_file(atm);
                return;
            }
        }
    }
    std::cout << "ATM can't issue such amount of money!";
}

int main(){
    std::srand(std::time(nullptr));
    while(true){
        std::cout << "Input comand you want to do: ";
        std::string comand;
        std::cin >> comand;
        std::vector<int> atm(1000);
        import_from_file(atm);
        if (comand == "+"){
            add_money(atm);
            break;
        }
        else if (comand == "-"){
            std::cout << "Input how much money you want to withdraw with an accuracy of 100: ";
            int money;
            int_input(money);
            withdraw_money(atm, money);
            break;
        }
        else std::cout << "Wrong input!\n";
    }
    return 0;
}