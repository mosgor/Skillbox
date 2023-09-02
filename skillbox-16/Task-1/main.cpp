#include <iostream>

int main(){
    float speed = 0.f;
    do{
        std::cout << "Speed delta: ";
        float speed_delta;
        std::cin >> speed_delta;
        char speed_str[] = "";
        speed += speed_delta;
        if (speed > 150) speed = 150;
        std::sprintf(speed_str, "%.1f", speed);
        std::cout << "Speed " << speed_str << "\n";
    }
    while(speed - 0.01 > 0);
    return 0;    
}