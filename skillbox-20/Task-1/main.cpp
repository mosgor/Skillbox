#include <iostream>
#include <fstream>
#include <string>

void input_name(std::string& name, std::string mode){
    bool correct;
    do{
        correct = true;
        std::cout << "Input " << mode << ": ";
        std::cin >> name;
        for (int i = 0; i < name.length(); ++i){
            if ((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z'))
                continue;
            else{
                std::cout << "Wrong input!\n";
                correct = false;
                break;
            }
        }
    } 
    while(!correct);
}

void input_date(std::string& date){
    while(true){
        std::cout << "Input date in DD.MM.YYYY format: ";
        std::cin >> date;
        if (date.length() != 10 || date[2] != '.' || date[5] != '.'){
            std::cout << "Wrong input!\n";
            continue;
        }
        int day = stoi(date.substr(0, 2)), month = stoi(date.substr(3, 2)), year = stoi(date.substr(6, 4));
        if (month > 0 && month <= 12 && year > 0){
            if (month == 2){
                if (year % 4 == 0 && day <= 29 && day > 0) break;
                else if (day <= 28 && day > 0) break;
            }
            else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
                if (day <= 31 && day > 0) break;
            }
            else if (day <= 30 && day > 0) break;
        }
        std::cout << "Wrong input!\n";
    }
}

void input_payment(int& payment){
    while(true){
        std::cout << "Input payment: ";
        std::cin >> payment;
        if (payment >= 0) break;
        std::cout << "Wrong input!\n";
    }
}

int main(){
    std::string name, surname, date;
    int payment;
    input_name(name, "name");
    input_name(surname, "surname");
    input_date(date);
    input_payment(payment);
    std::ofstream statement("statement.txt", std::ios::app);
    statement << name << " " << surname << " " << date << " " << payment << std::endl;
    statement.close();
    return 0;
}