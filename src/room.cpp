#include "libclean/Room.hpp" 
#include <fmt/core.h>
#include <string>
#include <vector>
#include <iostream>

int Room::nextID = 0;
Room::Room() 
    : mopTime(0), vacuumTime(0), scrubTime(0), mopping(0), vacuum(0), scrubber(0), roomSize(RoomSize::small),id(nextID++), area(0) {}


Room::Room(int mop, int vacuum, int scrub, RoomSize room)
    : mopping(0), vacuum(0), scrubber(0), id(nextID++), area(0) {
        this-> mopTime = mop;
        this-> vacuumTime = vacuum;
        this-> scrubTime = srub;
        this-> roomSize = room;
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


std::string Room::getIDAsString() const {
    return std::to_string(id); // Convert the integer ID to a string
}

void Room::printRoom() {
    string size = "";
        if(this->roomSize == RoomSize::small) {size = "small";}
                else if(this->roomSize == RoomSize::medium) {size = "medium";}
                else if(this->roomSize == RoomSize::large) {size = "large";}
        std::cout << "Room Size: " << size << std::endl;
        std::cout << "Mop Time: " << this->mopTime << std::endl;
        std::cout << "Vacuum Time: " << this->vacuumTime << std::endl;
        std::cout << "Scrub Time: " << this->scrubTime << std::endl;
}
