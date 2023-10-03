#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <mutex>
#include <map>
#include <vector>
#include <numeric>
#include <limits>

std::mutex mute;
std::vector<std::pair<std::string, int>> table;

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

void swim(std::string name, int speed){
    int position = 0, seconds = 0;
    while (position < 100){
        mute.lock();
        std::cout << "Swimmer " << name << " is on the " << position << " meter\n";
        mute.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        seconds += 1;
        position += speed;
    }
    mute.lock();
    std::cout << "Swimmer " << name << " got to the end!\n";
    table.push_back(std::pair<std::string, int> (name, seconds));
    mute.unlock();
}

int main(){
    std::string names[6];
    int speeds[6];
    for (int i = 1; i <= 6; i++){
        std::cout << "Input swimmer " << i << " name: ";
        std::cin >> names[i - 1];
        std::cout << "Input swimmer " << i << " speed: ";
        intInput(speeds[i - 1]);
    }
    std::thread swimmerOne(swim, names[0], speeds[0]);
    std::thread swimmerTwo(swim, names[1], speeds[1]);
    std::thread swimmerThree(swim, names[2], speeds[2]);
    std::thread swimmerFour(swim, names[3], speeds[3]);
    std::thread swimmerFive(swim, names[4], speeds[4]);
    std::thread swimmerSix(swim, names[5], speeds[5]);
    swimmerOne.join();
    swimmerTwo.join();
    swimmerThree.join();
    swimmerFour.join();
    swimmerFive.join();
    swimmerSix.join();
    std::cout << "Everybody got to the end!\n"; 
    std::cout << "Result table:\n";
    for (int i = 0; i < 6; i++){
        std::cout << i + 1 << ") " << table[i].first << " " << table[i].second << "\n";
    }
    return 0;
}