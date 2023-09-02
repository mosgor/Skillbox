#include <iostream>

int ways(int n, int k = 3, int pos = 0){
    if (pos > n) return 0;
    if (pos == n) return 1;
    int temp = 0;
    for (int i = 1; i <= k; i++){
        temp += ways(n, k, pos + i);
    }
    return temp;
}

int main(){
    std::cout << ways(3, 2);
    return 0;
}