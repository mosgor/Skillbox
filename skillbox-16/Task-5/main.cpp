#include <iostream>
#include <string>
#include <sstream>

enum switches 
{ 
    LIGHTS_INSIDE = 1, 
    LIGHTS_OUTSIDE = 2, 
    HEATERS = 4, 
    WATER_PIPE_HEATING = 8, 
    CONDITIONER = 16 
};

int main(){
    int time = 0, switches_state = 0, color_temperature;
    while(time <= 48){
        if (time % 24 == 0) color_temperature = 5000;
        std::cout << "Time, temperature inside, temperature outside, movement, lights:\n";
        std::cout << time % 24 << ":00 ";
        int temperature_inside, temperature_outside;
        std::string line, mov, lig;
        std::getline(std::cin, line);
        std::stringstream temp_stream(line);
        temp_stream >> temperature_inside >> temperature_outside >> mov >> lig;
        if ((lig != "off" && lig != "on") || (mov != "yes" && mov != "no")){
            std::cout << "Wrong input!\n";
            continue;
        }
        if (mov == "yes" && ~switches_state & LIGHTS_OUTSIDE && (time % 24 > 16 || time % 24 < 5)){
            std::cout << "Outside lights ON!\n";
            switches_state |= LIGHTS_OUTSIDE;
        }
        else if ((mov == "no" || (time % 24 <= 16 && time % 24 >= 5)) && switches_state & LIGHTS_OUTSIDE){
            std::cout << "Outside lights OFF!\n";
            switches_state &= ~LIGHTS_OUTSIDE;
        }
        if (lig == "on"){
            if (~switches_state & LIGHTS_INSIDE) std::cout << "Inside lights ON!\n";
            switches_state |= LIGHTS_INSIDE;
            if (time % 24 > 16 && time % 24 <= 20) color_temperature -= 575;
            std::cout << "Color temperature: " << color_temperature << "K\n";
        }
        else if (lig == "off" && switches_state & LIGHTS_INSIDE) {
            switches_state &= ~LIGHTS_INSIDE;
            std::cout << "Inside lights OFF!\n";
        }
        if (temperature_outside < 0 && ~switches_state & WATER_PIPE_HEATING){
            std::cout << "Water pipe heating ON!\n";
            switches_state |= WATER_PIPE_HEATING;
        }
        else if (temperature_outside > 5 && switches_state & WATER_PIPE_HEATING){
            std::cout << "Water pipe heating OFF!\n";
            switches_state &= ~ WATER_PIPE_HEATING;
        }
        if (temperature_inside < 22 && ~switches_state & HEATERS){
            std::cout << "Heaters ON!\n";
            switches_state |= HEATERS;
        }
        else if (temperature_inside >= 25 && switches_state & HEATERS){
            std::cout << "Heaters OFF!\n";
            switches_state &= ~HEATERS;
        }
        if (temperature_inside >= 30 && ~switches_state & CONDITIONER){
            std::cout << "Conditioner ON!\n";
            switches_state |= CONDITIONER;
        }
        else if (temperature_inside <= 25 && switches_state & CONDITIONER){
            std::cout << "Conditioner OFF!\n";
            switches_state &= ~CONDITIONER;
        }
        time++;
    }
    return 0;
}