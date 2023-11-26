#include <movie.h>
#include <fstream>
#include <map>
#include <iostream>

void Movie::getData(std::string path){
    std::ifstream file(path);
    if (file.is_open()) file >> dataBase;
    else std::cout << "There is no such file!\n";
    file.close();
}

Movie::Movie(){
    dataBase = nullptr;
};

Movie::Movie(std::string path){
    this->getData(path);
}

void Movie::findActor(std::string name){
    if (!dataBase.is_null()){
        for (auto i = dataBase.begin(); i != dataBase.end(); i++){
            std::map<std::string, std::string> actors = i.value()["Stars"];
            if(actors.count(name) != 0){
                std::cout << i.key() << " - " << actors[name] << std::endl;
            }
        }
    }
    else std::cout << "Open data base firstly!\n";
}