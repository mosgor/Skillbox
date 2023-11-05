#include <iostream>
#include <memory>

class Toy {   
    std::string name;
public:
    Toy(const std::string& inName) {
        name = inName;
    }
    std::string getNmae() {
        return name;
    }
    ~Toy() {
        std::cout << "Toy " << name << " was dropped " << std::endl;
    }
};

class Dog {
    std::shared_ptr<Toy> dogsToy = nullptr;
public:
    void getToy(std::shared_ptr<Toy> otherToy){
        if (otherToy == dogsToy) std::cout << "I already have this toy.\n";
        else if (otherToy.use_count() != 2) std::cout << "Another dog is playing with this toy.\n";
        else dogsToy = otherToy;
    }

    void dropToy(){
        if (dogsToy == nullptr) std::cout << "Nothing to drop\n";
        else dogsToy.reset();
    }
};

int main(){
    Dog dogy1;
    Dog dogy2;
    std::shared_ptr<Toy> ball = std::make_shared<Toy> ("ball");
    std::shared_ptr<Toy> bone = std::make_shared<Toy> ("bone");
    dogy1.dropToy();
    dogy2.getToy(ball);
    dogy1.getToy(ball);
    dogy2.getToy(bone);
    dogy1.getToy(ball);
    dogy2.dropToy();
    return 0;
}