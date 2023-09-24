#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>

class Branch{
    Branch* parent = nullptr;
    std::string name;
    std::vector<Branch> subBranches;
public:
    void coutnNeighbours(std::string elf){
        if (parent != nullptr){
            std::cout << "You can search for elf only on a tree\n";
            return;
        }
        for (int i = 0; i < subBranches.size(); i++){
            int emptyBranches = 0;
            bool isNeeded = false;
            for (int j = 0; j < subBranches[i].subBranches.size(); j++){
                if(subBranches[i].subBranches[j].name == "") emptyBranches++;
                else if(subBranches[i].subBranches[j].name == elf) isNeeded = true;
            }
            if (isNeeded){
                std::cout << "We found " << subBranches[i].subBranches.size() - 1 - emptyBranches << " neighbours of " 
                << elf << " on this branch.\n";
            }
        }
    }

    Branch(Branch* inParent = nullptr){
        parent = inParent;
        if (parent == nullptr){
            for (int i = 0; i < (std::rand() % 3) + 3; i++){
                Branch bigBranch(this);
                subBranches.push_back(bigBranch);
            }
        }
        else if (parent->parent == nullptr){
            std::cout << "New big branch!\n";
            for (int i = 0; i < (std::rand() % 2) + 2; i++){
                Branch littleBranch(this);
                subBranches.push_back(littleBranch);
            }
        }
        else{
            std::cout << "Input name of elf: ";
            std::string newName;
            std::cin >> newName;
            if (newName == "None") name = "";
            else name = newName;
        }
    };
};

int main(){
    std::srand(std::time(nullptr));
    std::vector<Branch> forest(5);
    std::cout << "Input name of elf that you want to find: ";
    std::string neededElf;
    std::cin >> neededElf;
    for(int i = 0; i < 5; i++) forest[i].coutnNeighbours(neededElf);
    return 0;
}