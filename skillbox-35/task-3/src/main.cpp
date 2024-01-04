#include <iostream>
#include <filesystem>
#include <vector>
#include <string>

auto recursiveGetFileNamesByExtension = [](
        std::filesystem::path path, 
        const std::string extension
    ){
        std::vector<std::string> names = {};
        for (auto p : std::filesystem::recursive_directory_iterator(path)){
            if (std::filesystem::is_regular_file(p.path())){
                if (p.path().extension() == extension){
                    names.push_back(p.path().stem().string());
                }
            }
        }
        return names;
    };

int main(){
    std::vector<std::string> names = recursiveGetFileNamesByExtension(
            "D:\\Projects\\C++\\skillbox\\skillbox-35\\task-3\\Example files",
            ".txt"
        );
    for (std::string a: names){
        std::cout << a << " ";
    }
    return 0;
}