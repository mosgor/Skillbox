#include <iostream>
#include <string>

int main(){
    char field[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char player_letter = 'X';
    std::cout << "Welcome to tic-tak-toe game!\n";
    for (int i = 0; i < 9; i++)
    {
        std::cout << "\n";
        for (int j = 0; j < 3; j++)
        {
            for (int z = 0; z < 3; z++){
                std::cout << " " << field[j][z];
                if (z != 2) std::cout << " |";
            }
            if (j != 2) std::cout << "\n-----------\n";
        }
        for (int j = 0; j < 3; j++)
        {
            std::string row = "";
            std::string column = "";
            for (int z = 0; z < 3; z++){
                row += field[j][z];
                column += field[z][j];
            }
            if (row == "XXX" || row == "OOO"){
                    std::cout << "\n\nPlayer '" << row[1] << "' wins!!!";
                    return 0;
                }
                if (column == "XXX" || column == "OOO"){
                    std::cout << "\n\nPlayer '" << column[1] << "' wins!!!";
                    return 0;
                }    
        }
        std::cout << "\n\nNow it's payer '" << player_letter << "' turn!\n\n";
        std::cout << "Input the coordinates (two numbers, firstly row, then column) where you want to put your letter: ";
        int a, b;
        std::cin >> a >> b;
        if (a < 1 || a > 3 || b < 1 || b > 3 || field[a - 1][b - 1] != ' '){
            std::cout << "\nIncorrect coordinates, try again.\n";
            continue;
        }
        field[a - 1][b - 1] = player_letter;
        if (player_letter == 'X') player_letter = 'O';
        else player_letter = 'X';
    }
    std::cout << "\n";
    for (int j = 0; j < 3; j++)
        {
            for (int z = 0; z < 3; z++){
                std::cout << " " << field[j][z];
                if (z != 2) std::cout << " |";
            }
            if (j != 2) std::cout << "\n-----------\n";
        }
    std::cout << "\n\nIt's a draw!";
    return 0;
}