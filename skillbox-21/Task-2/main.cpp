#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <numeric>

void int_input(int& num){
    while(true){
        std::cin >> num;
        if (std::cin.fail() || std::cin.peek() != '\n'){
            std::cerr << "Wrong input!\nTry again: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else break;
    }
}

void float_input(float& num){
    while(true){
        std::cin >> num;
        if (std::cin.fail() || std::cin.peek() != '\n'){
            std::cerr << "Wrong input!\nTry again: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else break;
    }
}

enum building_type{
    house,
    garage,
    shed,
    sauna
};

enum room_type{
    bedroom,
    kitchen,
    bathroom,
    children_room,
    living_room
};

struct room{
    int space;
    room_type type;
};

struct level{
    int count_of_rooms = 1;
    float height = 2.7f;
    std::vector<room> rooms;
};

struct building{
    building_type type;
    int space;
    int count_of_floors = 1;
    std::vector<level> floors;
};

struct area{
    int count_of_buildings;
    std::vector<building> buildings;
};

struct village{
    int cout_of_areas;
    std::vector<area> areas;
};

void creating_rooms(room& this_room){
    std::cout << "Input how many space this room takes: ";
    int temp;
    int_input(temp);
    this_room.space = temp;
    std::string type;
    while(true){
        std::cout << "Input type of room: ";
        std::getline(std::cin, type);
        if (type == "bedroom") this_room.type = bedroom;
        else if (type == "kitchen") this_room.type = kitchen;
        else if (type == "bathroom") this_room.type = bathroom;
        else if (type == "children room") this_room.type = children_room;
        else if (type == "living room") this_room.type = living_room;
        else{
            std::cout << "Wrong type!\n";
            continue;
        }
        break;
    }
}

void creating_floor(level& this_floor){
    while(true){
        std::cout << "Input how many rooms are on this floor: ";
        int count_of_rooms;
        int_input(count_of_rooms);
        this_floor.count_of_rooms = count_of_rooms;
        if(this_floor.count_of_rooms < 2 || this_floor.count_of_rooms > 4){
            std::cout << "Wrong count of rooms!\n";
        }
        else break;
    }
    std::cout << "Input heigth of the floor: ";
    float heigth;
    float_input(heigth);
    this_floor.height = heigth;
    for (int i = 0; i < this_floor.count_of_rooms; i++){
        std::cout << "Let's create " << i + 1 << " room\n";
        creating_rooms(this_floor.rooms[i]); 
    }
}

void creating_building(building& this_building){
    std::cout << "Input how many space this building takes: ";
    int space;
    int_input(space);
    this_building.space = space;
    std::string type;
    while(true){
        std::cout << "Input type of building: ";
        std::cin >> type;
        if (type == "garage"){
            this_building.type = garage;
            this_building.floors.resize(this_building.count_of_floors);
            break;
        }
        else if (type == "shed"){
            this_building.type = shed;
            this_building.floors.resize(this_building.count_of_floors);
            break;
        }
        else if (type == "sauna"){
            this_building.type = sauna;
            this_building.floors.resize(this_building.count_of_floors);
            break;
        }
        else if (type == "house"){
            this_building.type = house;
            while(true){
                std::cout << "Input how many floors are in house: ";
                int count_of_floors;
                int_input(count_of_floors);
                this_building.count_of_floors = count_of_floors;
                if (this_building.count_of_floors < 1 || this_building.count_of_floors > 3){
                    std::cout << "Wrong count of floors!\n";
                }
                else break;
            }
            this_building.floors.resize(this_building.count_of_floors);
            for (int i = 0; i < this_building.count_of_floors; i++){
                std::cout << "Let's create " << i + 1 << " floor:\n";
                creating_floor(this_building.floors[i]);           
            }
            break;
        }
        else std::cout << "Wrong input!\n";
    }
}

void creating_area(area& area1){
    std::cout << "Input how many buildings are in this area: ";
    int count_of_buildings;
    int_input(count_of_buildings);
    area1.count_of_buildings = count_of_buildings;
    area1.buildings.resize(area1.count_of_buildings);
    for (int i = 0; i < area1.count_of_buildings; i++){
        std::cout << "Let's create " << i + 1 << " building:\n";
        creating_building(area1.buildings[i]);           
    }
}

int main(){
    village village1;
    std::cout << "Input how many areas are in your village: ";
    int count_of_areas;
    int_input(count_of_areas);
    village1.cout_of_areas = count_of_areas;
    village1.areas.resize(village1.cout_of_areas);
    for (int i = 0; i < village1.cout_of_areas; i++){
        std::cout << "Let's create " << i + 1 << " area:\n";
        creating_area(village1.areas[i]);       
    }   
    return 0;
}