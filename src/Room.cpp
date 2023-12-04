#include "libclean/Room.hpp" 
#include <fmt/core.h>
#include <string>
#include <vector>
#include <iostream>
#include <random>

int Room::nextID = 0;
Room::Room() : 
        mopTime(100), 
        vacuumTime(100), 
        scrubTime(100), 
        mopping(0), 
        vacuum(0), 
        scrubber(0), 
        roomSize(RoomSize::small), 
        id(nextID), 
        area(0) {
        nextID++;

        std::random_device rd;                                                                     //random number generator
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distribution(0, 1);
        int random_number = distribution(gen);
        if (random_number == 0){
            cleanLevel = cleanStatus::clean;
        }
        else{
            cleanLevel = cleanStatus::dirty;
        }
        
    }


Room::Room(RoomSize room) : 
        mopping(0), 
        vacuum(0), 
        scrubber(0), 
        id(nextID), 
        currentRobots(vector<Robot>()), 
        area(0) {
        if(room == RoomSize::small) {
            mopTime = 100;
            vacuumTime = 100;
            scrubTime = 100;
        } else if(room == RoomSize::medium) {
            mopTime = 150;
            vacuumTime = 150;
            scrubTime = 150;
        } else if(room == RoomSize::large) {
            mopTime = 200;
            vacuumTime = 200;
            scrubTime = 200;
        } else if(room == RoomSize::home) {
            mopTime = 0;
            vacuumTime = 0;
            scrubTime = 0;
        }

        this-> roomSize = room;
        nextID++;

        std::random_device rd;                                                                     //random number generator
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distribution(0, 1);
        int random_number = distribution(gen);
        if (random_number == 0){
            cleanLevel = cleanStatus::clean;
        }
        else{
            cleanLevel = cleanStatus::dirty;
        }
    }

int Room::getID() const {
    return id;
}

void Room::setRoomSize(RoomSize newSize) {
    this->roomSize = newSize;
}

RoomSize Room::getRoomSize() const {
    return roomSize;
}


int Room::getMopTime() const {
    return mopTime;
}

int Room::getVacuumTime() const {
    return vacuumTime;
}

int Room::getScrubTime() const {
    return scrubTime;
}

int Room::getNumMopping() const {
    return mopping;
}

int Room::getNumVacuum() const {
    return vacuum;
}

int Room::getNumScrubber() const {
    return scrubber;
}

cleanStatus Room::getClean() const{
    return cleanLevel;
}

void Room::setClean(cleanStatus level){
    this->cleanLevel = level;
}

std::string Room::getIDAsString() const {
    return std::to_string(id); // Convert the integer ID to a string
}

void Room::printRoom() {
    string size = "";
    string clean1 = "";
        if(this->roomSize == RoomSize::small) {size = "small";}
                else if(this->roomSize == RoomSize::medium) {size = "medium";}
                else if(this->roomSize == RoomSize::large) {size = "large";}
                else if(this->roomSize == RoomSize::home) {size = "Robot Home";}
        std::cout << "RoomID: " << this->id << std::endl;
        std::cout << "Room Size: " << size << std::endl;
        if(this->roomSize != RoomSize::home) {
            std::cout << "Mop Time: " << this->mopTime << std::endl;
            std::cout << "Vacuum Time: " << this->vacuumTime << std::endl;
            std::cout << "Scrub Time: " << this->scrubTime << std::endl;
            if(this->cleanLevel == cleanStatus::clean) {clean1 = "Clean";}
                else if(this->cleanLevel == cleanStatus::dirty) {clean1 = "Dirty";}
                else if(this->cleanLevel == cleanStatus::cleaning) {clean1 = "Cleaning";}
                else if(this->cleanLevel == cleanStatus::doNotClean) {clean1 = "Do Not Clean";}
            std::cout << "Clean Status: " << clean1 << std::endl;         
        }
}

void Room::printCurrentRobots() {
        for(int i = 0; i < currentRobots.size(); i++) {
                currentRobots[i].printRobot();
        }
}