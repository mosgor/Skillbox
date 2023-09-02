#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

void format_path (std::string& path){
    std::string new_path;
    int length = path.size();
    for (int i = 1; i < length - 1; i++){
        if (path[i] == '\\' && path[i+1] != '\\' && path[i-1] != '\\') new_path += "\\\\";
        else new_path += path[i];
    }
    path = path[0] + new_path + path[length - 1];
}

int main(){
    std::cout << "Input path of the file to check if it is PNG or not: ";
    std::string path;
    std::ifstream photo;
    while (true){
        std::cout << "Input the path of the file you want to read: ";
        std::cin >> path;
        format_path(path);
        photo.open(path, std::ios::binary);
        if (photo.is_open() == true) break;
        else std::cerr << "Wrong input.\n";
    }
    if (path.substr(path.rfind('.'), 4) == ".png"){
        char check[4];
        photo.read(check, 4);
        char png[] = "0PNG";
        png[0] = -119;
        if (std::memcmp(check, png, 4) == 0) {
            std::cout << "This file is PNG";
            photo.close();
            return 0;
        }
    }
    photo.close();
    std::cout << "This file is not PNG";
    return 0;
}