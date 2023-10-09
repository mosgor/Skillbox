#include <iostream>
#include <string>
#include <vector>

class Talent{
protected:
    std::vector<std::string> talents;
    virtual void add_talent() = 0;
};

class Swimming: virtual public Talent{
    void add_talent(){
        talents.push_back("Swim");
    }
public:
    Swimming(){
        this->add_talent();
    }
};

class Counting: virtual public Talent{
    virtual void add_talent(){
        talents.push_back("Count");
    }
public:
    Counting(){
        this->add_talent();
    }
};

class Dancing: virtual public Talent{
    virtual void add_talent(){
        talents.push_back("Dance");
    }
public:
    Dancing(){
        this->add_talent();
    }
};

class Dog: public Counting, public Dancing, public Swimming{
    std::string name;
    void add_talent(){};
public:
    void show_talents(){
        std::cout << "This is " << name << " and is has some talents:\n";
        for (int i = 0; i < talents.size(); i++){
            std::cout << "It can \"" << talents[i] << "\"\n";
        }
    }

    Dog(std::string inName): name (inName){}; 
};

int main(){
    std::cout << "Input dog's name: ";
    std::string name;
    std::cin >> name;
    Dog d(name);
    d.show_talents();
    return 0;
}