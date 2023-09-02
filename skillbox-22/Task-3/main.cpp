#include <iostream>
#include <string>
#include <map>

void count_letters(std::string word, std::map<char, int>& letters){
    for (int i = 0; i < word.length(); i++){
        if (letters.count(word[i]) != 0) letters[word[i]]++;
        else letters[word[i]] = 1;
    }
}

bool anagram(std::string first_word, std::string second_word){
    std::map<char, int> first_word_letters;
    count_letters(first_word, first_word_letters);
    std::map<char, int> second_word_letters;
    count_letters(second_word, second_word_letters);
    return first_word_letters == second_word_letters;
}

int main(){
    std::cout << "Input first word: ";
    std::string first_word;
    std::cin >> first_word;
    std::cout << "Input second word: ";
    std::string second_word;
    std::cin >> second_word;
    if (anagram(first_word, second_word)) std::cout << "These words are anagrams!";
    else std::cout << "These words aren't anagrams";
    return 0;
}