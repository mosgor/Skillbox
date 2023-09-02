#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct information_about_payment{
    std::string name;
    std::string surname;
    std::string date;
    int sum;
};

void list(std::vector<information_about_payment>& payments){
    std::ifstream statement("statement.txt");
    if (!statement.is_open()){
        std::cerr << "Error opening statement!";
        exit(1);
    }
    int iterator = 0;
    while (!statement.eof()){
        std::string name;
        statement >> name;
        if (name != ""){
            payments.resize(iterator + 1);
            payments[iterator].name = name;
            statement >> payments[iterator].surname >> payments[iterator].date >> payments[iterator].sum;
            iterator++;
        }
    }
    statement.close();
}

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

void add(){
    std::string name, surname, date;
    int payment;
    input_name(name, "name");
    input_name(surname, "surname");
    input_date(date);
    input_payment(payment);
    std::ofstream statement("statement.txt", std::ios::app);
    if (!statement.is_open()){
        std::cerr << "Error opening statement!";
        exit(1);
    }
    statement << name << " " << surname << " " << date << " " << payment << std::endl;
    statement.close();
}

int main(){
    while (true){
        std::cout << "Input the command: ";
        std::string command;
        std::cin >> command;
        if (command == "list") {
            std::vector<information_about_payment> payments;
            list(payments);
            for (int i = 0; i < payments.size(); i++){
                std::cout << payments[i].name << " " << payments[i].surname << " " << payments[i].date << " " << payments[i].sum << std::endl;
            }
        }
        else if (command == "add") add();
        else{
            std::cout << "Wrong input!\n";
            continue;
        }
        break;
    }
    return 0;
}