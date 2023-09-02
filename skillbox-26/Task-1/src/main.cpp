#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>

class Track{
    std::string name = "SomeSong";
    int duration = std::rand() % 121 + 60;
    std::time_t temp = std::time(nullptr);
    std::tm* creationDate = std::localtime(&temp);
  public:
    std::string getName(){
        return name;
    }
    
    void setName(std::string newName){
        name = newName;
    }

    int getDuration(){
        return duration;
    }

    void setDuration(int newDuration){
        duration = newDuration;
    }

    std::tm* getCreationDate(){
        return creationDate;
    }

    void setCreationDate(std::tm* newCreationDate){
        creationDate = newCreationDate;
    }

    bool equalityCheck(Track otherTrack){
        if (name == otherTrack.getName() && duration == otherTrack.getDuration()){
            std::tm* otherDate = otherTrack.getCreationDate();
            if (creationDate->tm_year == otherDate->tm_year && creationDate->tm_mon == otherDate->tm_mon && creationDate->tm_mday == otherDate->tm_mday){
                return true;
            }
        }
        return false;
    }
};

enum class WalkmanState {playing, paused, off};

class Walkman{
    std::time_t temp = std::time(nullptr);
    std::vector<Track> tracks = {{}, {}, {}};
    Track currentTrack;
    WalkmanState state {WalkmanState::off};
  public:
    void play(){
        if (state == WalkmanState::off){
            std::cout << "Input name of song: ";
            std::string name;
            std::cin >> name;
            for (Track track : tracks){
                if (track.getName() == name){
                    std::cout << "Starting playing track " << track.getName();
                    std::cout << ". Duration: " << track.getDuration();
                    std::cout << ". Date of creation: " << std::put_time(track.getCreationDate(), "%d.%m.%Y");
                    std::cout << std::endl;
                    currentTrack = track;
                    state = WalkmanState::playing;
                    return;
                }
            }
            std::cout << "There is no such track!\n";
        }
    }

    void pause(){
        if (state == WalkmanState::playing){
            std::cout << "Track is paused!\n";
            state = WalkmanState::paused;
        }
    }

    void next(){
        if (state != WalkmanState::off){
            Track newTrack = currentTrack;
            while (newTrack.equalityCheck(currentTrack)){
                newTrack = tracks[std::rand() % tracks.size()];
            }
        }
    }

    void stop(){
        if (state != WalkmanState::off){
            std::cout << "Stopping playing track " << currentTrack.getName() << std::endl;
        }
    }
};

int main(){
    std::srand(std::time(nullptr));
    Walkman test;
    while(true){
        std::cout << "Input command: ";
        std::string command;
        std::cin >> command;
        if (command == "play") test.play();
        else if (command == "pause") test.pause();
        else if (command == "next") test.next();
        else if (command == "stop") test.stop();
        else if (command == "exit") exit(0);
        else std::cout << "Unknown command!\n";
    }
    return 0;
}