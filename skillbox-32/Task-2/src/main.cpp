#include <iostream>
#include <fstream>
#include <movie.h>

int main(){
    Movie mov;
    mov.getData("D:\\Projects\\C++\\skillbox\\skillbox-32\\Task-2\\Films.json");
    mov.findActor("Robert Downey Jr.");
    mov.findActor("Cillian Murphy");
    return 0;
}
