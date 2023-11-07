//Robot Class File
#include "libclean/Robot.hpp" 
#include <iostream>

using namespace std;

Robot::Robot(RobotType type, RobotSize size) :
        isActive(false),
        isBroken(false),
        robotType(type),
        robotSize(size),
        batteryLife(100),
        probFailure(0),
        destination(Room()),
        currentTask(Task()),
        completedTasks(vector<Task>())
{}

Robot::Robot(const Robot& other) :
        isActive(false),
        isBroken(false),
        robotType(other.robotType),
        robotSize(other.robotSize),
        batteryLife(100),
        probFailure(0),
        destination(Room()),
        currentTask(Task()),
        completedTasks(vector<Task>())
{}


Robot::~Robot() {}

bool Robot::getActive() {
        return this->isActive;
}

bool Robot::getBrokenStatus() {
        return this->isBroken;
};

void Robot::setBrokenStatus(bool status) {
        this->isBroken = status;
        return;
}

RobotType Robot::getRobotType() {
        return this->robotType;
}

RobotSize Robot::getRobotSize() {
        return this->robotSize;
}

int Robot::getBattery() {
        return this->batteryLife;
}

void Robot::charge() {
        this->batteryLife = 100;
        return;
}

Room Robot::getDestination() {
        return this->destination;
}

void Robot::setDestination(Room newDest) {
        this->destination = newDest;
        return;
}

Task Robot::getTask() {
        return currentTask;
}

void Robot::setTask(Task task) {
        this->currentTask = task;
        return;
}

vector<Task> Robot::getCompletedTasks() {
        return this->completedTasks;
}

void Robot::printRobot() {
        string size  = "";
        string type = "";

        if(this->robotSize == RobotSize::small) {size = "small";}
                else if(this->robotSize == RobotSize::medium) {size = "medium";}
                else if(this->robotSize == RobotSize::large) {size = "large";}

        if(this->robotType == RobotType::mopper) {type = "mopper";}
                else if(this->robotType == RobotType::scrubber) {type = "scrubber";}
                else if(this->robotType == RobotType::sweeper) {type = "sweeper";}

        std::cout << "Robot Size: " << size << std::endl;
        std::cout << "Robot Type: " << type << std::endl;
}
