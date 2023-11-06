#include "libclean/Task.hpp"
// #include "libclean/Room.hpp"
// #include "libclean/Robot.hpp"

// Constructor
Task::Task() : numRobots(0), mopTime(0), vacuumTime(0), scrubTime(0), isCompleted(true) {}
/*
void Task::setNumRobots(int num) {
    numRobots = num;
}

void Task::addWorkingRobot(Robot* robot) {
    // Assuming Robot class has an interface to determine if it's already in the vector
    // if (std::find(workingRobots.begin(), workingRobots.end(), robot) == workingRobots.end())
    workingRobots.push_back(robot);
}

void Task::removeWorkingRobot(Robot* robot) {
    // workingRobots.erase(std::remove(workingRobots.begin(), workingRobots.end(), robot), workingRobots.end());
}
*/

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

//others
/*
std::vector<Robot*> Task::getWorkingRobots() const {
    return workingRobots;
}
Room* Task::getTaskLocation() const {
    return taskLocation;
}
*/
