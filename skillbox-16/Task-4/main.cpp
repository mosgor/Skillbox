#include <iostream>
#include <string>
#include <vector>

enum note 
{ 
    DO = 1, 
    RE = 2, 
    MI = 4, 
    FA = 8, 
    SOL = 16, 
    LA = 32, 
    SI = 64 
};

int main(){
    std::vector<std::vector<int>> melody(12);
    int i = 0;
    std::cout << "Input 12 accords that can consist of any notes: ";
    while (i < 12){
        int notes;
        std::cin >> notes;
        std::string str = std::to_string(notes);
        if (str.find('9') != -1 || str.find('8') != -1 || str.find('0') != -1){
            std::cout << "Invalid notes";
            continue;
        }
        for (int j = 0; j < str.length(); ++j){
            int num = int(str[j]) - '0' - 1;
            int index = 1 << num;
            melody[i].push_back(index);
        }
        i++;
    }
    std::cout << "Your melody: ";
    for (int i = 0; i < melody.size(); i++){
        for (int j = 0; j < melody[i].size(); j++){
            if (melody[i][j] & DO) std::cout << "DO ";
            else if (melody[i][j] & RE) std::cout << "RE ";
            else if (melody[i][j] & MI) std::cout << "MI ";
            else if (melody[i][j] & FA) std::cout << "FA ";
            else if (melody[i][j] & SOL) std::cout << "SOL ";
            else if (melody[i][j] & LA) std::cout << "LA ";
            else if (melody[i][j] & SI) std::cout << "SI ";
        }
    }
    return 0;
}