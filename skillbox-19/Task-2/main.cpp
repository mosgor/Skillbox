#include <iostream>
#include <string>
#include <fstream>

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
    std::string path;
    std::ifstream file;
    while (true){
        std::cout << "Input the path of the file you want to read: ";
        std::cin >> path;
        format_path(path);
        file.open(path, std::ios::binary);
        if (file.is_open() == true) break;
        else std::cerr << "Wrong input.\n";
    }
    char buffer[21];
    std::cout << "File contents:\n";
    do {
        file.read(buffer, 20);
        buffer[file.gcount()] = 0;
        std::cout << buffer;
    } 
    while (file.gcount() == 20);
    file.close();
    return 0;
}