#include <iostream>
#include <memory>
#include <map>

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

class shared_ptr_toy{
    Toy* object = nullptr;
    static std::map<Toy*, int> toys;
public:
    shared_ptr_toy(Toy* someToy){
        object = someToy;
        if (toys.count(object) == 0) toys[object] = 1;
        else toys[object]++;
    }

    shared_ptr_toy(){};

    shared_ptr_toy& operator=(const shared_ptr_toy& otherPtr){
        if (otherPtr.object != object){
            toys[object] -= 1;
            object = otherPtr.object;
        }
        toys[otherPtr.object] += 1;
        return *this;
    }

    shared_ptr_toy(shared_ptr_toy* otherPtr){
        if (otherPtr->object != object){
            toys[object] -= 1;
            object = otherPtr->object;
        }
        toys[otherPtr->object] += 1;
    }

    int use_count(){
        return toys[object];
    }

    Toy* get(){
        return object;
    }

    ~shared_ptr_toy(){
        toys[object]--;
        if (toys[object] == 0){
            delete object;
            object = nullptr;
        }
    }
};

std::map<Toy*, int> shared_ptr_toy::toys;

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

shared_ptr_toy make_shared_toy(std::string inName){
    Toy* someToy = new Toy(inName);
    return shared_ptr_toy(someToy);
}

shared_ptr_toy make_shared_toy(shared_ptr_toy someToy){
    return shared_ptr_toy(someToy);
}

int main(){
    // Dog dogy1;
    // Dog dogy2;
    // std::shared_ptr<Toy> ball = std::make_shared<Toy> ("ball");
    // std::shared_ptr<Toy> bone = std::make_shared<Toy> ("bone");

    // std::shared_ptr<Toy> bab = std::make_shared<Toy> ("test");
    // std::shared_ptr<Toy> bab2 = bab;
    // std::shared_ptr<Toy> bab1 = bab;
    // std::cout << bab.use_count() << std::endl;
    // std::cout << bab1.use_count() << std::endl;
    // std::cout << bab2.use_count() << std::endl;
    // bab1.reset();
    // std::cout << bab2.use_count() << std::endl;

    shared_ptr_toy bb = make_shared_toy("test");
    shared_ptr_toy bb2(bb);
    shared_ptr_toy bb1 = bb;
    std::cout << bb.use_count() << std::endl;
    std::cout << bb1.use_count() << std::endl;
    std::cout << bb2.use_count() << std::endl;

    // dogy1.dropToy();
    // dogy2.getToy(ball);
    // dogy1.getToy(ball);
    // dogy2.getToy(bone);
    // dogy1.getToy(ball);
    // dogy2.dropToy();
    return 0;
}