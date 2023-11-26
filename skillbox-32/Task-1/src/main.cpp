#include <iostream>
#include "nlohmann/json.hpp"
#include <fstream>

int main(){
    nlohmann::json film;
    film["Country"] = {"United States", "United Kingdom"};
    film["Production companies"] = {"Syncopy Inc.", "Atlas Entertainment"};
    film["Writers"] = {"Christopher Nolan", "Kai Bird", "Martin Sherwin"};
    film["Director"] = "Christopher Nolan";
    film["Producers"] = {"Emma Thomas", "Charles Roven", "Christopher Nolan"};
    film["Stars"] = {{"Oppenheimer", "Cillian Murphy"}, {"Lewis Strauss", "Robert Downey Jr."}};
    std::ofstream file("Oppenheimer.json");
    file << film; 
    file.close();
    return 0;
}
