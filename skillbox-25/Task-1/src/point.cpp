#include "point.h"
#include <iostream>

point get_new_point(){
    std::cout << "Input x coordinate: ";
    double x_coord, y_coord;
    std::cin >> x_coord;
    std::cout << "Input y coordinate: ";
    std::cin >> y_coord;
    point new_p = {x_coord, y_coord};
    return new_p;
}

void print_point(point pnt){
    std::cout << "X coordinate: " << pnt.x_cord << "\n";
    std::cout << "Y coordinate: " << pnt.y_cord << "\n";
}

bool compare_points(point first, point second){
    if (first.x_cord == second.x_cord && first.y_cord == second.y_cord) return true;
    return false;
}