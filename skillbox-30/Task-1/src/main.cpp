#include <iostream>
#include <string>
#include <cpr/cpr.h>

int main(){
    while(true){
        std::cout << "Input type of request you want to send: ";
        std::string type;
        std::cin >> type;
        if (type == "get"){
            cpr::Response response = cpr::Get(cpr::Url("http://httpbin.org/" + type));
            std::cout << response.text << std::endl;
        }
        else if (type == "post"){
            cpr::Response response = cpr::Post(cpr::Url("http://httpbin.org/" + type));
            std::cout << response.text << std::endl;
        }
        else if (type == "put"){
            cpr::Response response = cpr::Put(cpr::Url("http://httpbin.org/" + type));
            std::cout << response.text << std::endl;
        }
        else if (type == "delete"){
            cpr::Response response = cpr::Delete(cpr::Url("http://httpbin.org/" + type));
            std::cout << response.text << std::endl;
        }
        else if (type == "patch"){
            cpr::Response response = cpr::Patch(cpr::Url("http://httpbin.org/" + type));
            std::cout << response.text << std::endl;
        }
        else if (type == "exit"){
            break;
        }
        else std::cout << "Wrong input!\n";
    }
    return 0;
}