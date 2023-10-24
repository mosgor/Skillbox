#include <iostream>
#include <map>
#include <string>
#include <cpr/cpr.h>

int main(){
    std::string key = "", value = "";
    std::map<std::string, std::string> args;
    while(true){
        std::cout << "Input key: ";
        std::cin >> key;
        if (key == "post" || key == "get") break;
        std::cout << "Input value: ";
        std::cin >> value;
        args[key] = value;
    }
    std::map<std::string, std::string>::iterator it;
    if (key == "post"){
        std::vector<cpr::Pair> arguments;
        for (it = args.begin(); it != args.end(); it++){
            arguments.push_back({it->first, it->second});
        }
        cpr::Response response = cpr::Post(cpr::Url("http://httpbin.org/post"), cpr::Payload(arguments.begin(), arguments.end()));
        std::cout << response.text;
    }
    else {
        std::string url = "http://httpbin.org/get";
        if (!args.empty()){
            url += "?";
            for (it = args.begin(); it != args.end(); it++){
                url += it->first + "=" + it->second + "&";
            }
            url.resize(url.length() - 1);
        }
        cpr::Response response = cpr::Get(cpr::Url(url));
        std::cout << response.text;
    }
    return 0;
}