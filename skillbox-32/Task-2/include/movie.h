#pragma once
#include <string>
#include "nlohmann/json.hpp"

class Movie{
    nlohmann::json dataBase;
public:
    Movie(); 

    Movie(std::string path);

    void findActor(std::string name);

    void getData(std::string path);
};