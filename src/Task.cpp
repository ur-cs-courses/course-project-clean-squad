#include "libhello/Task.hpp"

// Constructor
Task::Task()
    : numRobots(0), mopTime(0), vacuumTime(0), scrubTime(0), isCompleted(false) {}

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

void Task::setVacuumTime(int vacuumTime) {
    this->vacuumTime = vacuumTime;
}

void Task::setScrubTime(int scrubTime) {
    this->scrubTime = scrubTime;
}

void Task::setIsCompleted(bool isCompleted) {
    this->isCompleted = isCompleted;
}
