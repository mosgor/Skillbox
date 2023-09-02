#include <iostream>

void set_ship(bool field[][10], int size){
    int first_coordinate[2];
    int second_coordinate[2];
    if (size == 1){
        std::cout << "Input coordinates: ";
        std::cin >> first_coordinate[0] >> first_coordinate[1];
        second_coordinate[0] = first_coordinate[0];
        second_coordinate[1] = first_coordinate[1];
    }
    else{
        std::cout << "Input the beginning coordinates: ";
        std::cin >> first_coordinate[0] >> first_coordinate[1];
        std::cout << "Input the end coordinates: ";
        std::cin >> second_coordinate[0] >> second_coordinate[1];
    }
    if (0 <= first_coordinate[0] && first_coordinate[0] < 10 && 0 <= first_coordinate[1] && first_coordinate[1] < 10 
            && 0 <= second_coordinate[0] && second_coordinate[0] < 10 && 0 <= second_coordinate[1] && second_coordinate[1] < 10){ 
        if (first_coordinate[0] == second_coordinate[0]){
            int min, max = 0;
            if (first_coordinate[1] > second_coordinate[1]){
                max = first_coordinate[1];
                min = second_coordinate[1];
            }
            else{
                max = second_coordinate[1];
                min = first_coordinate[1];
            }
            bool is_empty = true;
            for (int i = min; i <= max; i++){
                if (field[first_coordinate[0]][i]){
                    is_empty = false;
                }
            }
            if (is_empty && max - min == size - 1){
                for (int i = min; i <= max; i++){
                    field[first_coordinate[0]][i] = true;
                }
                return;
            }
        }
        else if (first_coordinate[1] == second_coordinate[1]){
            int min, max = 0;
            if (first_coordinate[0] > second_coordinate[0]){
                max = first_coordinate[0];
                min = second_coordinate[0];
            }
            else{
                max = second_coordinate[0];
                min = first_coordinate[0];
            }
            bool is_empty = true;
            for (int i = min; i <= max; i++){
                if (field[i][first_coordinate[1]]){
                    is_empty = false;
                }
            }
            if (is_empty && max - min == size - 1){
                for (int i = min; i <= max; i++){
                    field[i][first_coordinate[1]] = true;
                }
                return;
            }
        }       
    }
    std::cout << "\nIncorect coordinates, please try again.\n";
    set_ship(field, size);
}

void show_field(bool field[][10], bool enemy){
    for (int i = 0; i <= 10; i++){
        if (i > 0) std::cout << i-1 << " ";
        else std::cout << "  ";
        for (int j = 0; j < 10; j++){
            if (i == 0) std::cout << j << " ";
            else if (field[i - 1][j] && !enemy) std::cout << "S ";
            else if (field[i - 1][j] && enemy) std::cout << "X ";
            else std::cout << "~ ";
        }
        std::cout << "\n";
    }
}

void initialize_field(bool field[][10]){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            field[i][j] = false;
        }
    }
}

void ships(bool field[][10]){
    initialize_field(field);
    std::cout << "To set ships you must input coordinates of the beginning and of the end of a ship.\n";
    std::cout << "Coordinates looks like two numbers from 0 to 9. First number means row, second column.\n";
    std::cout << "Firstly lets set size 1 ships!\n";
    for (int i = 0; i < 4; i++){
        std::cout << "Your field: \n";
        show_field(field, false);
        set_ship(field, 1);
    }
    std::cout << "\nNow lets set size 2 ships!\n";
    for (int i = 0; i < 3; i++){
        std::cout << "Your field: \n";
        show_field(field, false);
        set_ship(field, 2);
    }
    std::cout << "\nNow lets set size 3 ships!\n";
    for (int i = 0; i < 2; i++){
        std::cout << "Your field: \n";
        show_field(field, false);
        set_ship(field, 3);
    }
    std::cout << "\nAnd in the end we need to set size 4 ship!\n";
    std::cout << "Your field: \n";
    show_field(field, false);
    set_ship(field, 4);
    std::cout << "Your field: \n";
    show_field(field, false);
}

bool win_check(bool field[][10]){
    bool flag = true;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (field[i][j]) flag = false;
        }
    }
    return flag;
}

void shoot(bool field[][10], bool enemy_field[][10]){
    std::cout << "Enemy's field (it shows where you shoot before):\n";
    show_field(enemy_field, true);
    int coordinate[2];
    std::cout << "Input coordinates: ";
    std::cin >> coordinate[0] >> coordinate[1];
    enemy_field[coordinate[0]][coordinate[1]] = true;
    if (field[coordinate[0]][coordinate[1]]){
        std::cout << "You hit!\n";
        field[coordinate[0]][coordinate[1]] = false;
        if (win_check(field)){
            return;
        }
        std::cout << "You may shoot again.\n";
        shoot(field, enemy_field);
    }
    else std::cout << "You missed!\n";
}

int main(){
    bool field1[10][10];
    bool field2[10][10];
    bool enemy_field1[10][10];
    bool enemy_field2[10][10];
    std::cout << "Welcome to Battleship game!\n\n";
    std::cout << "Lets set first player's ships.\n";
    ships(field1);
    std::cout << "\nNow it's second player's turn to set ships.\n";
    ships(field2);
    initialize_field(enemy_field1);
    initialize_field(enemy_field2);
    std::cout << "\nGame starts!\n\n";
    while(true){
        std::cout << "\nFirst player shoots!\n";
        std::cout << "Your field:\n";
        show_field(field1, false);
        shoot(field2, enemy_field1);
        if (win_check(field2)){
            std::cout << "First player wins!!!";
            break;
        }
        std::cout << "\nSecond player shoots!\n";
        std::cout << "Your field:\n";
        show_field(field2, false);
        shoot(field1, enemy_field2);
        if (win_check(field1)){
            std::cout << "Second player wins!!!";
            break;
        }
    }
    return 0;
}