#include <iostream>
#include <vector>
#include <unordered_set>
#include <memory>



int main(){
    std::vector<int> list {1, 2, 2, 5, 6, 6, 9, 6};
    list = *([list](){
        std::unordered_set<int> nums = {};
        std::unordered_set<int> doubledNums = {};
        for (auto i : list){
            if (nums.count(i) == 1) doubledNums.insert(i);
            nums.insert(i);
        }
        for (auto i : doubledNums) nums.erase(i);
        return std::make_unique<std::vector<int>>(nums.begin(), nums.end());
    }());
    for (auto i : list){
        std::cout << i << " ";
    }
    return 0;
}