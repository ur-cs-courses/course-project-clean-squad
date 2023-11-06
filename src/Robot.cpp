//Robot Class File

#include "Robot.hpp"
#include "Room.hpp"
#include "Task.hpp"
#include "iostream"

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

/*
int main() {
        Robot robot1 = Robot(RobotType::mopper, RobotSize::large);
        cout << robot1.getActive() << endl;
        robot1.getBattery();
        robot1.setBrokenStatus(true);
        cout << robot1.getBrokenStatus() << endl;
}
*/
