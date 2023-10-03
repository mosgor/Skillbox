#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <limits>
#include <numeric>
#include <chrono>

std::mutex mute;
bool isFree = true;

void intInput (int& num){
    while (true)
    {
        std::cin >> num;
        if (std::cin.fail() || std::cin.peek() != '\n' || num <= 0){
            std::cerr << "Wrong input!\nTry again: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else break;
    }
}

void trainWentOut(int time, char train){
    std::this_thread::sleep_for(std::chrono::seconds(time));
    if (!isFree){
        std::cout << "Train " << train << " waits for entering the station\n";
    }
    mute.lock();
    isFree = false;
    std::cout << "Train " << train << " arrived at the station\n";
    std::string input;
    while(input != "depart") std::cin >> input;
    std::cout << "Train " << train << " went out from the station\n";
    isFree = true;
    mute.unlock();
}

int main(){
    std::cout << "Input how long train A woul be getting to the station: ";
    int time;
    intInput(time);
    std::thread a (trainWentOut, time, 'A');
    std::cout << "Input how long train B woul be getting to the station: ";
    intInput(time);
    std::thread b (trainWentOut, time, 'B');
    std::cout << "Input how long train C woul be getting to the station: ";
    intInput(time);
    std::thread c (trainWentOut, time, 'C');
    a.join();
    b.join();
    c.join();
    std::cout << "All trains went out from the station";
    return 0;
}