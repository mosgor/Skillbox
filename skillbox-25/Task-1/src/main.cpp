#include <iostream>
#include "point.h"
#include "operations.h"
#include <string>

int main(){
    while(true){
        std::cout << "Input what surgical tool you need: ";
        std::string tool;
        std::cin >> tool;
        if (tool == "scalpel"){
            std::cout << "Input point where you want to start cut.\n";
            point start_cut = get_new_point();
            std::cout << "Input point where you want to end cut.\n";
            point end_cut = get_new_point();
            scalpel(start_cut, end_cut);
            while(true){
                std::cout << "Input what surgical tool you need: ";
                std::cin >> tool;
                if (tool == "hemostat"){
                    std::cout << "Input where you want to use hemostat.\n";
                    point temp = get_new_point();
                    hemostat(temp);
                }
                else if (tool == "tweezers"){
                    std::cout << "Input where you want to use tweezers.\n";
                    point temp = get_new_point();
                    tweezers(temp);
                }
                else if (tool == "suture"){
                    std::cout << "Enter the starting point of the seam.\n";
                    point start_seam = get_new_point();
                    std::cout << "Enter the ending point of the seam.\n";
                    point end_seam = get_new_point();
                    suture(start_cut, end_cut);
                    if (compare_points(start_cut, start_seam) && compare_points(end_cut, end_seam)){
                        std::cout << "Operation completed!";
                        break;
                    }
                }
                else std::cout << "Wrong input!\n";
            }
            break;
        }
        else std::cout << "You can't start operation with this tool!\n";
    }
    return 0;
}