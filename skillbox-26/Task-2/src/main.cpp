#include <iostream>
#include <string>
#include <map>
#include <vector>

class Number{
    std::string number;
  public:
    void setNumber(std::string newNumber){
        bool correct = true;
        if (newNumber.length() == 12 && newNumber[0] == '+' && newNumber[1] == '7'){
            for (int i = 2; i < 12; i++){
                if (newNumber[i] > '9' || newNumber[i] < '0') correct = false;
            }
        }
        else correct = false;
        if (correct) number = newNumber;
        else{
            std::cout << "Incorrect number, try again: ";
            std::cin >> newNumber;
            setNumber(newNumber);
        }
    }

    std::string getNumber(){
        return number;
    }
};

class Phone{
    std::vector<std::pair<Number, std::string>> phoneBook;
  public:
    void add(){
        std::cout << "Input number you want to add: ";
        std::string newNumber;
        std::cin >> newNumber;
        Number number;
        number.setNumber(newNumber);
        for (int i = 0; i < phoneBook.size(); i++){
            if (number.getNumber() == phoneBook[i].first.getNumber()){
                std::cout << "There already is such number\n";
                return;
            }
        }
        std::cout << "Input contact name: ";
        std::string contactName;
        std::cin >> contactName;
        std::pair<Number, std::string> newPair(number, contactName);
        phoneBook.push_back(newPair);
    }

    void call(){
        std::cout << "Input phone or contact name: ";
        std::string request;
        std::cin >> request;
        std::vector<Number> suitableNumbers;
        for (int i = 0; i < phoneBook.size(); i++){
            if (phoneBook[i].first.getNumber() == request){
                std::cout << "CALL " << request << std::endl;
                return;
            }
            if (phoneBook[i].second == request) suitableNumbers.push_back(phoneBook[i].first);
        }
        if (suitableNumbers.size() == 1){
            std::cout << "CALL " << suitableNumbers[0].getNumber() << std::endl;
            return;
        }
        else if (suitableNumbers.size() == 0){
            std::cout << "There is no such contact.\n";
            return;
        }
        else{
            std::cout << "There are more then one contact with this name. Here they are:\n";
            for (int i = 0; i < suitableNumbers.size(); i++){
                std::cout << suitableNumbers[i].getNumber() << std::endl;
            }
        }
    }

    void sms(){
        std::cout << "Input phone or contact name: ";
        std::string request;
        std::cin >> request;
        std::vector<Number> suitableNumbers;
        for (int i = 0; i < phoneBook.size(); i++){
            if (phoneBook[i].first.getNumber() == request){
                std::cout << "Input message: ";
                std::string message;
                std::cin >> message;
                std::cout << "Send message.";
                return;
            }
            if (phoneBook[i].second == request) suitableNumbers.push_back(phoneBook[i].first);
        }
        if (suitableNumbers.size() == 1){
            std::cout << "Input message: ";
            std::string message;
            std::cin >> message;
            std::cout << "Send message.";
            return;
        }
        else if (suitableNumbers.size() == 0){
            std::cout << "There is no such contact.\n";
            return;
        }
        else{
            std::cout << "There are more then one contact with this name. Here they are:\n";
            for (int i = 0; i < suitableNumbers.size(); i++){
                std::cout << suitableNumbers[i].getNumber() << std::endl;
            }
        }
    }

    void exit(){
        abort();
    }
};

int main(){
    std::string command;
    Phone phone;
    while(true){
        std::cout << "Input command: ";
        std::cin >> command;
        if (command == "add") phone.add();
        else if (command == "call") phone.call();
        else if (command == "sms") phone.sms();
        else if (command == "exit") phone.exit();
        else std::cout << "Wrong input!\n";
    }   
    return 0;
}