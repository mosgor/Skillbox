#include <iostream>

bool contains(const char* a, const char* b){
    int i = 0;
    while (*(a + i) != '\0'){
        int j = 0;
        bool correct = true;
        while (*(b + j) != '\0'){
            if (*(a + i) == '\0' || *(a + i + j) != *(b + j)){
                correct = false;
                break;
            }
            j++;
        }
        if (correct) return true;
        i++;
    }
    return false;
}

int main(){
    const char* a = "Hello world";
    const char* b = "wor";
    const char* c = "banana";
    std::cout << contains(a, b) << " " << contains(a, c);
    return 0;
}