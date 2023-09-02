#include <iostream>
#include <string>
#include <map>
#include <vector>

int main(){
    std::map<std::string, std::string> phone_book;
    while(true){
        std::cout << "Input your request: ";
        std::string request;
        std::getline(std::cin, request);
        std::vector<std::string> all_words;
        int temp = request.find(' ');
        while(temp != -1){
            temp = request.find(' ');
            all_words.push_back(request.substr(0, temp));
            request = request.substr(temp + 1, request.length());
        }
        if (all_words.size() == 2){
            if (all_words[0][0] != '+' && (all_words[0][0] < '0' || all_words[0][0] > '9')) std::cout << "There is some mistake in number.\n";
            else if (phone_book.count(all_words[0]) == 0) phone_book[all_words[0]] = all_words[1];
            else std::cout << "This number has already been added to phone book.\n";
        }
        else if (all_words.size() == 0){
            if ((request[0] >= 'a' && request[0] <= 'z') || (request[0] >= 'A' && request[0] <= 'Z')){
                for (std::map<std::string, std::string>::iterator iter = phone_book.begin(); iter != phone_book.end(); iter++){
                    if (request == iter->second) std::cout << iter->first << '\n';
                }
            }
            else if (phone_book.count(request) != 0) std::cout << phone_book.at(request) << '\n';
            else std::cout << "There is no such number or name in the phone book.\n";
        }
        else{
            std::cout << "Wrong input!\n";
        }
    }
    return 0;
}