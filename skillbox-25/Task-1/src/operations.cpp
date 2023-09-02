#include "operations.h"
#include "point.h"
#include <iostream>

void scalpel(point first, point second){
    std::cout << "Made cut between entered coordinates!\n";
}

void hemostat(point pnt){
    std::cout << "The clamp is set according to the entered coordinates!\n";
}

void tweezers(point pnt){
    std::cout << "Tweezers are used on the entered coordinates!\n";
}

void suture(point first, point second){
    std::cout << "A seam is made between the entered coordinates!\n";
}