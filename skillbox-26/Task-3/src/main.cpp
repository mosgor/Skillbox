#include <iostream>
#include <string>

class Monitor{
    bool monitor[50][80];
  public:
    void setWindow(Window window){
        for (int i = 0; i < 50; i++){
            for (int j = 0; j < 80; j++){
                monitor[i][j] = 0;
            }
        }
    }

    void display(){
        for (int i = 0; i < 50; i++){
            for (int j = 0; j < 80; j++){
                std::cout << monitor[i][j];
            }
        }
    }
};

class Window{

};

int main(){
    
    return 0;
}