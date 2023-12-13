#include <iostream>
#include <map>
#include <string>
#include <exception>

int main(){
    std::cout << "Input how many articles are in the shop: ";
    int articles;
    try{
        std::cin >> articles;
        if (articles <= 0) throw std::invalid_argument("It must be bigger then zero number");
    }
    catch (std::invalid_argument exc){
        std::cout << exc.what();
        return 1;
    }
    std::map<std::string, int> shop;
    for(int i = 0; i < articles; i++){
        std::cout << "Input article and amount of this good in the shop: ";
        std::string article;
        int amount;
        try{
            std::cin >> article >> amount;
            if (amount <= 0) throw std::invalid_argument("It must be bigger then zero number");
        }
        catch (std::invalid_argument exc){
            std::cout << exc.what();
            return 1;
        }
        shop[article] = amount;
    }
    std::map<std::string, int> cart;
    while(true){
        std::cout << "Input add or remove then article of good and it's ammount: ";
        std::string action, article;
        int amount;
        try{
            std::cin >> action >> article >> amount;
            if (action == "add"){
                if (shop.count(article) == 0){
                    throw std::invalid_argument("There is no such article in the shop");  
                    continue;      
                }
                if (amount > shop[article] || amount < 0) throw std::invalid_argument("There is no such amount of good in this shop");
                else{
                    shop[article] -= amount;
                    cart[article] += amount;
                }
            }
            else if (action == "remove"){
                if (cart.count(article) == 0){
                    throw std::invalid_argument("There is no such article in the cart");  
                    continue;
                }
                if (amount > cart[article] || amount < 0) throw std::invalid_argument("There is no such amount of good in your cart");
                else{
                    shop[article] += amount;
                    cart[article] -= amount;
                }
            }
            else throw std::runtime_error("Wrong action");
        }
        catch(std::runtime_error exc){
            std::cout << exc.what() << std::endl;
        }
        catch(std::invalid_argument exc){
            std::cout << exc.what() << std::endl;
        }
    } 
    return 0;
}