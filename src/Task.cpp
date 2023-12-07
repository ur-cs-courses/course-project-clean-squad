#include "libclean/Task.hpp"
#include <iostream>

int Task::nextID = 1;
Task::Task() {}

Task::Task(std::vector<Robot> robots, Room taskLocation){
    roomID = taskLocation.getID();
    this->numRobots = robots.size();
    this->mopTime = taskLocation.getMopTime();
    this->vacuumTime = taskLocation.getVacuumTime();
    this->scrubTime = taskLocation.getScrubTime();
    if(taskLocation.getClean() == cleanStatus::dirty){
        this->isCompleted = false;
    }
    else{this->isCompleted = false;}

    id = nextID;
    nextID++;
    if(robots.size() == 0) {
        nextID--;
    }
}

// Getters
int Task::getNumRobots() const {
    return numRobots;
}

int Task::getMopTime() const {
    return mopTime;
}

int Task::getVacuumTime() const {
    return vacuumTime;
}

int Task::getScrubTime() const {
    return scrubTime;
}

bool Task::getIsCompleted() const {
    return isCompleted;
}

// Setters
void Task::setNumRobots(int numRobots) {
    this->numRobots = numRobots;
}

void Task::setMopTime(int mopTime) {
    this->mopTime = mopTime;
}
int Task::getId() const {
    return nextID;
}
int Task::getRoomID() const { return roomID; }

void Task::setVacuumTime(int vacuumTime) {
    this->vacuumTime = vacuumTime;
}

void Task::setScrubTime(int scrubTime) {
    this->scrubTime = scrubTime;
}

void Task::setIsCompleted(bool isCompleted) {
    this->isCompleted = isCompleted;
}

void Task::printTask() {
    std::cout << "Here's tasks info:\n";
    std::cout << "Task ID: " << id << std::endl;
    std::cout << "Room ID: " << roomID << std::endl;
    std::cout << "Required Mop Time: " << this->mopTime << std::endl;
    std::cout << "Required Scrub Time: " << this->scrubTime << std::endl;
    std::cout << "Required Vacuum Time: " << this->vacuumTime << std::endl;
}

int Task::getID() {
    return id;
}

std::vector<Robot> Task::getRobots() const {
    return robots;
}

