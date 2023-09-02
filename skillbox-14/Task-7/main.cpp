#include <iostream>

int main(){
    std::cout << "Input matrix of heights:\n";
    int matrix[4][4];
    for (int i = 0; i < 4; i++){
        std::cin >> matrix[i][0] >> matrix[i][1] >> matrix[i][2] >> matrix[i][3];
    }
    int world[10][4][4];
    for (int level = 0; level < 10; level++){
        for (int y = 0; y < 4; y++){
            for (int x = 0; x < 4; x++){
                if (matrix[y][x] >= level){
                    world[level][y][x] = 1;
                }
                else world[level][y][x] = 0;
            }
        }
    }
    while (true){
        int level;
        std::cout << "Input slice level:\n";
        std::cin >> level;
        if (level < 0 || level > 10){
            std::cout << "Something went wrong, try again.\n";
            continue;
        }
        for (int y = 0; y < 4; y++){
            for (int x = 0; x < 4; x++){
                std::cout << world[level][y][x] << " ";
            }
            std::cout << "\n";
        }
    }
}