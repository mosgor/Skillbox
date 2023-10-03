#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <cstdlib>
#include <ctime>

int couter = 0;
std::vector<std::string> orders;
std::vector<std::string> readyOrders;
std::mutex mute;

void giveOrder(){
    std::vector<std::string> possibleFood = {"pizza", "soup", "steak", "salad", "sushi"};
    int givedOrders = 0;
    while(givedOrders != 10)
    {
        mute.lock();
        std::string temp = possibleFood[std::rand() % 5];
        orders.push_back(temp);
        std::cout << temp << " is ordered\n";
        givedOrders++;
        mute.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(std::rand() % 6 + 5));
    }
}

void makeOrder(){
    int madeOrders = 0;
    while (madeOrders != 10)
    {
        if (orders.size() == 0) continue;
        mute.lock();
        std::string temp = orders.back();
        orders.pop_back();
        std::cout << temp << " is being cooked\n";
        mute.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(std::rand() % 6 + 10));
        mute.lock();
        readyOrders.push_back(temp);
        std::cout << temp << " is cooked\n";
        madeOrders++;
        mute.unlock();
    }
}

void deliverOrder(){
    int deliveredOrders = 0;
    while(deliveredOrders != 10)
    {
        if (readyOrders.size() == 0) continue;
        mute.lock();
        std::string temp = readyOrders.back();
        readyOrders.pop_back();
        std::cout << temp << " is being delivered\n";
        deliveredOrders++;
        mute.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(30));
    }
}

int main(){
    std::srand(std::time(nullptr));
    std::thread visiters(giveOrder);
    std::thread kitchen(makeOrder);
    std::thread courier(deliverOrder);
    visiters.join();
    kitchen.join();
    courier.join();
    return 0;
}