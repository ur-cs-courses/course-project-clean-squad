#include "libclean/Room.hpp" 
#include <fmt/core.h>
#include <string>
#include <vector>

Room::Room() 
    : mopTime(0), vacuumTime(0), scrubTime(0), mopping(0), vacuum(0), scrubber(0), roomSize(RoomSize::small), area(0) {}

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