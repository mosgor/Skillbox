#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <numeric>
#include <cstring>

struct character{
    std::string name = "Enemy";
    int health = std::rand() % 101 + 50;
    int armor = std::rand() % 51;
    int damage = std::rand() % 16 + 15;
    int position[2] = {std::rand() % 21, std::rand() % 21};
};

void int_input(int& num){
    while (true)
    {
        std::cin >> num;
        if (std::cin.fail() || std::cin.peek() != '\n' || num < 0){
            std::cerr << "Wrong input!\nTry again: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else break;
    }
}

void show_map(char game_map[][20]){
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            std::cout << game_map[i][j] << " ";
        }
        std::cout << '\n';
    }
}

void set_characters(char game_map[][20], character (&enemies)[5], character& player){
    for(int i = 0; i < 5; i++){
        int y_pos = enemies[i].position[0];
        int x_pos = enemies[i].position[1];
        if (game_map[y_pos][x_pos] != '.'){
            enemies[i].position[0] = std::rand() % 21;
            enemies[i].position[1] = std::rand() % 21;
            i--;
        }
        else game_map[y_pos][x_pos] = 'E';
    }
    while (game_map[player.position[0]][player.position[1]] != '.'){
        player.position[0] = std::rand() % 21;
        player.position[1] = std::rand() % 21;
    }
    game_map[player.position[0]][player.position[1]] = 'P';
}

character create_player_character(){
    std::cout << "Input your character name: ";
    std::string name;
    std::cin >> name;
    std::cout << "Input your character health level: ";
    int health;
    int_input(health);
    std::cout << "Input your character armor level: ";
    int armor;
    int_input(armor);
    std::cout << "Input your character damage: ";
    int damage;
    int_input(damage);
    character player = {name, health, armor, damage};
    return player;
}

int main(){
    std::srand(std::time(nullptr));
    character enemies[5];
    character player = create_player_character();
    char game_map[20][20];
    std::memset(game_map, '.', sizeof(game_map));
    set_characters(game_map, enemies, player);
    show_map(game_map);
    return 0;
}