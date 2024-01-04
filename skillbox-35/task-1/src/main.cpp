#include <iostream>

int main(){
    std::initializer_list<int> a {1, 2, 3, 4, 5};
    for (auto i : a){
        std::cout << i << " ";
    }
    return 0;
}