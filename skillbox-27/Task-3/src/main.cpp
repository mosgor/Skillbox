#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

class Worker{
protected:
    std::string name;
};

class Employee: public Worker{
    char task = 0;
public:
    Employee(std::string inName){
        name = inName;
    }

    void setTask(char inTask) {
        task = inTask;
        std::cout << "Employee " << name << " got task " << task << "\n";
    }
    
    char getTask() {return task;}
};

class Manager: public Worker{
    std::vector<Employee> team;
    int teamNumber;
    char taskTypes[4] = "ABC";
    bool allDone = false;
public:
    Manager(int inNumber, std::string inName): teamNumber(inNumber){
        name = inName;
        std::cout << "Input how many employees are in " << teamNumber + 1 << " team: ";
        int countOfEmployees;
        std::cin >> countOfEmployees;
        for (int i = 1; i <= countOfEmployees; i++){
            std::cout << "Input employee " << i << " name: ";
            std::string employeeName;
            std::cin >> employeeName;
            team.push_back(Employee(employeeName));
        }
    }

    bool setTasks(int directive){
        std::srand(teamNumber + directive);
        int tasksCount = std::rand() % team.size() + 1;
        std::cout << "Manager " << name << " got new directive.\n";
        for (int i = 0; i < team.size(); i++){
            if (team[i].getTask() == 0 && tasksCount > 0){
                team[i].setTask(taskTypes[std::rand() % 3]);
                tasksCount--;
            }
        }
        allDone = true;
        for (int i = 0; i < team.size(); i++){
            if (team[i].getTask() == 0) {
                allDone = false;
                break;
            }
        }
        return allDone;
    }
};

class Head: public Worker{
    std::vector<Manager> company;
public:
    Head(int teams, std::string inName){
        name = inName;
        for (int i = 0; i < teams; i++){
            std::cout << "Input manager " << i+1 << " name: ";
            std::string managerName;
            std::cin >> managerName;
            company.push_back(Manager(i, managerName));
        }
    }

    void newDirective(int directive){
        bool allHaveTask = true;
        for (int i = 0; i < company.size(); i++){
            if (!company[i].setTasks(directive)) allHaveTask = false;
        }
        if (allHaveTask) {
            std::cout << "Everyone have task!";
            exit(0);
        }
    }
};

int main(){
    std::cout << "Input number of teams: ";
    int count;
    std::cin >> count;
    std::cout << "Input name of head of the company: ";
    std::string name;
    std::cin >> name;
    Head head(count, name);
    while(true){
        std::cout << "Input directive number: ";
        int number;
        std::cin >> number;
        head.newDirective(number);
    }
    return 0;
}