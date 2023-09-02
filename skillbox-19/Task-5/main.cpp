#include <iostream>
#include <string>
#include <fstream>

std::string get_question(int sector){
    std::string path = "D:\\Projects\\C++\\skillbox-19\\Task-5\\Questions\\" + std::to_string(sector) + ".txt";
    std::ifstream question_file;
    question_file.open(path);
    std::string question = "";
    while (!question_file.eof()){
        std::string word;
        question_file >> word;
        question += word + " ";
    }
    question_file.close();
    return question;
}

std::string get_answer(int sector){
    std::string path = "D:\\Projects\\C++\\skillbox-19\\Task-5\\Answers\\" + std::to_string(sector) + ".txt";
    std::ifstream answer_file;
    answer_file.open(path);
    std::string answer;
    answer_file >> answer;
    answer_file.close();
    return answer;
}

void input_offset(int& sector, bool* answered_sectors){
    while(true){
            std::cout << "Input the drum offset: ";
            int offset;
            std::cin >> offset;
            sector = (sector + offset) % 13;
            if (answered_sectors[sector]){
                std::cout << "This question is already answered!\n";
            }
            else{
                answered_sectors[sector] = true;
                break;
            }
        }
}

int main(){
    int player_score = 0, spectator_score = 0, sector = 0;
    std::string winner;
    bool answered_sectors[13] = {false};
    while (player_score < 6 && spectator_score < 6){
        input_offset(sector, answered_sectors);
        std::cout << "The question is: " << get_question(sector + 1) << std::endl;
        std::cout << "Input your answer: ";
        std::string answer;
        std::cin >> answer;
        if (answer == get_answer(sector + 1)){
            std::cout << "Score to player!\n";
            player_score++;
            winner = "Player";
        }
        else{
            std::cout << "Score to spectator!\n";
            spectator_score++;
            winner = "Spectator";
        }
    }
    std::cout << "Winner is " << winner;
    return 0;
}