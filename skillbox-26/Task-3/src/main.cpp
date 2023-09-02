#include <iostream>
#include <string>

class Window{
    double coordinates[2] = {0, 0};
    double width = 10, height = 5;
  public:
    double* getCoordinates(){
        return coordinates;
    }

    double getWidth(){
        return width;
    }

    double getHeight(){
        return height;
    }

    void move(double xSwift, double ySwift){
        if (coordinates[0] + xSwift > 79 || coordinates[0] + xSwift < 0){
            if (coordinates[1] + ySwift > 49 || coordinates[1] + ySwift < 0){
                std::cout << "Left angle of window can't be out of monitor!\n";
                return;
            }
        }
        coordinates[0] += xSwift;
        coordinates[1] += ySwift;
    }

    void resize(){
        std::cout << "Input new width of window: ";
        double newWidth;
        std::cin >> newWidth;
        if (newWidth < 2 || newWidth > 80){
            std::cout << "Window can't have such width!\n";
            return;
        }
        std::cout << "Input new height of window: ";
        double newHeight;
        std::cin >> newHeight;
        if (newHeight < 2 || newHeight > 50){
            std::cout << "Window can't have such height!\n";
            return;
        }
        height = newHeight;
        width = newWidth;
    }
};

class Monitor{
    bool monitor[50][80] = {};
    void setWindow(Window window){
        for (int y = 0; y < 50; y++){
            for (int x = 0; x < 80; x++){
                double* leftAngle = window.getCoordinates();
                if (x >= leftAngle[0] && x < leftAngle[0] + window.getWidth() && y >= leftAngle[1] && y < leftAngle[1] + window.getHeight()){
                    monitor[y][x] = 1;
                }
                else monitor[y][x] = 0;
            }
        }
    }

  public:
    void display(Window window){
        setWindow(window);
        for (int i = 0; i < 50; i++){
            for (int j = 0; j < 80; j++){
                std::cout << monitor[i][j];
            }
            std::cout << std::endl;
        }
    }
};

int main(){
    Monitor monitor;
    Window window;
    while(true){
        std::cout << "Input command: ";
        std::string command;
        std::cin >> command;
        if (command == "move"){
            std::cout << "Input by what width value do you want to move the window: ";
            double xSwift, ySwift;
            std::cin >> xSwift;
            std::cout << "Input by what height value do you want to move the window: ";
            std::cin >> ySwift;
            window.move(xSwift, ySwift);
        }
        else if (command == "resize") window.resize();
        else if (command == "display") monitor.display(window);
        else if (command == "close") exit(0);
        else std::cout << "Wrong input!\n";
    }
    return 0;
}