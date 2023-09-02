#include <iostream>

void initialize(bool arr[][12]){
    for (int i = 0; i < 12; i++){
        for (int j = 0; j < 12; j++){
            arr[i][j] = true;
        }        
    }
}

bool show_wrap(bool arr[][12]){
    bool check = true;
    for (int i = 0; i < 12; i++){
        for (int j = 0; j < 12; j++){
            if (arr[i][j]){
                std::cout << "o ";
                check = false;
            }
            else std::cout << "x ";
        }
        std::cout << "\n";        
    }
    return check;
}

void square_pop(bool arr[][12], int x1, int y1, int x2, int y2){
    if (x1 < 0 || x1 > 11 || x2 < 0 || x2 > 11 || y1 < 0 || y1 > 11 || y2 < 0 || y2 > 11){
        std::cout << "Incorrect input!\n";
        return ;
    }
    if (x2 < x1){
        int mid = x1;
        x1 = x2;
        x2 = mid;
    }
    if (y2 < y1){
        int mid = y1;
        y1 = y2;
        y2 = mid;
    }
    for (int i = y1; i <= y2; i++){
        for (int j = x1; j <= x2; j++){
            if (arr[i][j]){
                arr[i][j] = false;
                std::cout << "Pop!\n";
            }
        }
    }
}

int main(){
    bool bubble_wrap[12][12];
    initialize(bubble_wrap);
    while(true){
        std::cout << "Your bubble wrap:\n";
        bool all_popped = show_wrap(bubble_wrap);
        if (all_popped) break;
        std::cout << "Input coordinates of square to pop.\nFirst coordinate: ";
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1;
        std::cout << "Second coordinate: ";
        std::cin >> x2 >> y2;
        square_pop(bubble_wrap, x1 - 1, y1 - 1, x2 - 1, y2 - 1);
    }
    std::cout << "All bubbles are popped!";
    return 0;
}