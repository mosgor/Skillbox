#include <iostream>
#include <vector>

void swapvec(std::vector<int>& vec, int* arr){
    for (int i = 0; i < vec.size();++i){
        int temp = *(arr + i);
        *(arr + i) = vec[i];
        vec[i] = temp;
    }
}

int main(){
    std::vector<int> vect = {1, 2, 3, 4};
    int arr[] = {2, 4, 6, 8};
    swapvec(vect, arr);
    for (int i : vect){
        std::cout << i << " ";
    }
    std::cout << "\n";
    for (int i : arr){
        std::cout << i << " ";
    }
    return 0;
}