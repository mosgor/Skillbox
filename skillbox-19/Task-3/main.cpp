#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::ifstream statement;
    statement.open("D:\\Projects\\C++\\skillbox-19\\Task-3\\statement.txt");
    std::string name, surname, date, answer;
    int payment, total_sum, biggest = 0;
    while (!statement.eof()){
        statement >> name >> surname >> payment >> date;
        total_sum += payment;
        if (payment > biggest){
            answer = name + " " + surname;
            biggest = payment;
        }
    }
    statement.close();
    std::cout << "Sum of payments: " << total_sum << "\n";
    std::cout << "Recipient with a larger amount of money: " << answer;
    return 0;
}