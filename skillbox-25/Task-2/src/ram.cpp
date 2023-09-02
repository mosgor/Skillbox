#include "ram.h"

int buffer[8] = {0, 0, 0, 0, 0, 0, 0, 0};

void ram_write(int new_data[8]){
    for (int i = 0; i < 8; i++) buffer[i] = new_data[i]; 
}

void ram_read(int container[8]){
    for (int i = 0; i < 8; i++) container[i] = buffer[i]; 
}