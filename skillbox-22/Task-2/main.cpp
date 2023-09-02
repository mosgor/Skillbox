#include <iostream>
#include <string>
#include <map>

int main(){
    std::map<std::string, int> registry;
    std::map<std::string, int>::iterator position;
    while(true){
        position = registry.begin();
        std::cout << "Input your command: ";
        std::string command;
        std::cin >> command;
        if (command == "Next"){
            if (position == registry.end()) break;
            std::cout << position->first << std::endl;
            position->second--;
            if (position->second == 0) registry.erase(position->first);
        }
        else{
            if (registry.count(command) != 0){
                registry[command]++;
            }
            else registry[command] = 1;
        }
    } 
    return 0;
}