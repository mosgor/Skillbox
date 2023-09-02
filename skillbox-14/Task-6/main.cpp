#include <iostream>

int main(){
    int arr[5][5];
    int a = -1;
    for (int i = 0; i < 5; i++){
        a *= -1;
        for (int j = 0; j < 5; j++){
            arr[i][(i % 2) * 4 + j * a] = 5 * i + j; 
        }
    }
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}