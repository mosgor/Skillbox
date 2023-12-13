#include <vector>
#include <iostream>
#pragma once

template <typename T1, typename T2>
class Registry{
    std::vector<std::pair<T1, T2>> pairs;    
public:
    void add(T1 key, T2 value){
        pairs.push_back(std::make_pair(key, value));
    }

    void remove(T1 key){
        for(int i = 0; i < pairs.size(); i++){
            if (pairs[i].first == key){
                pairs.erase(pairs.begin() + i);
                i--;
            }
        }
    }

    void print(){
        for(int i = 0; i < pairs.size(); i++){
            std::cout << pairs[i].first << ": " << pairs[i].second << std::endl;
        }
    }

    std::vector<T2> find(T1 key){
        std::vector<T2> elements;
        for(int i = 0; i < pairs.size(); i++){
            if (pairs[i].first == key){
                elements.push_back(pairs[i].second);
            }
        }
        return elements;
    }
};