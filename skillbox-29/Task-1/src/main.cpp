#include <iostream>
#include <string>
#include <vector>

class Talent{
public:
    virtual std::string show_talents() = 0;
};

class Swimming: virtual public Talent{
public:
    std::string show_talents(){
        return "Swim";
    }
};

class Counting: virtual public Talent{
public:
    std::string show_talents(){
        return "Count";
    }
};

class Dancing: virtual public Talent{
public:
    std::string show_talents(){
        return "Dance";
    }
};

class Dog{
    std::string name;
    std::vector<Talent*> talents;
public:
    void show_talents(){
        std::cout << "This is " << name;
        if (!talents.empty()){
            std::cout << " and it has some talents:\n";
            for (int i = 0; i < talents.size(); i++){
                std::cout << "It can \"" << talents[i]->show_talents() << "\"\n";
            }
        }
        else{
            std::cout << " and it has no talents\n";
        }
    }

    void add_talent(Talent* someTalent){
        talents.push_back(someTalent);
    }

    Dog(std::string inName): name (inName){}; 

    ~Dog(){
        for (int i = 0; i < talents.size(); i++){
            delete talents[i];
        }
    }
};

int main(){
    std::cout << "Input dog's name: ";
    std::string name, temp;
    std::cin >> name;
    Dog d(name);
    std::cout << "Can it swim?\n";
    std::cin >> temp;
    if (temp == "Yes" || temp == "y" || temp == "yes"){d.add_talent(new Swimming);}
    std::cout << "Can it dance?\n";
    std::cin >> temp;
    if (temp == "Yes" || temp == "y" || temp == "yes"){d.add_talent(new Dancing);}
    std::cout << "Can it count?\n";
    std::cin >> temp;
    if (temp == "Yes" || temp == "y" || temp == "yes"){d.add_talent(new Counting);}
    d.show_talents();
    return 0;
}