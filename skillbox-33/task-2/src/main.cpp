#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <exception>

class Fish : public std::exception{
public:
    const char* what() const noexcept override{
        return "You catched fish!";
    }
};

class Boot : public std::exception{
public:
    const char* what() const noexcept override{
        return "You catched boot :-(";
    }
};

int main(){
    std::srand(std::time(nullptr));
    char pond[9];
    std::memset(pond, '~', 9);
    for (int i = 0; i < 4; i++){
        int temp = std::rand() % 9;
        if (i == 0) pond[temp] = 'f';
        else{ 
            if (pond[temp] == '~'){
                pond[temp] = 'b';
            }
            else i--;
        }
    }
    int steps = 1;
    while (true){
        for (int i = 1; i < 10; i++){
            std::cout << i << " ";
        }
        std::cout << std::endl;
        for (char pos : pond){
            if (pos == 'b' || pos == 'f') std::cout << "~ ";
            else std::cout << pos << ' ';
        }
        std::cout << std::endl;
        std::cout << "Input in which cell you want to fish: ";
        try{
            int cell;
            std::cin >> cell;
            cell--;
            if (cell < 0 || cell > 8) throw std::invalid_argument("There is no such cell");
            else if (pond[cell] == 'f') throw Fish();
            else if (pond[cell] == 'b') throw Boot();
            else {
                pond[cell] = 'x';
                steps++;
            }
        }
        catch(std::invalid_argument exc){
            std::cout << exc.what() << std::endl;
        }
        catch(Fish exc){
            std::cout << exc.what() << std::endl;
            std::cout << "It took you " << steps << " steps";
            return 0;
        }
        catch(Boot exc){
            std::cout << exc.what() << std::endl;
            return 0;
        }
    }
}