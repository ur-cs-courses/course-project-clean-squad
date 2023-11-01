//Robot Class File

#include "Robot.hpp"
#include "iostream"

using namespace std;

Robot::Robot(RobotType type, RobotSize size) :
        isActive(false),
        isBroken(false),
        robotType(type),
        robotSize(size),
        batteryLife(100),
        probFailure(0)
        /*
        destination;
        currentTask;
        completedTasks;
        */
{}

Robot::Robot(const Robot& other) :
        isActive(false),
        isBroken(false),
        robotType(other.robotType),
        robotSize(other.robotSize),
        batteryLife(100),
        probFailure(0)
        /*
        destination;
        currentTask;
        completedTasks;
        */
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
        return robotType;
}

RobotSize Robot::getRobotSize() {
        return robotSize;
}

int Robot::getBattery() {
        return this->batteryLife;
}

void Robot::charge() {
        this->batteryLife = 100;
        return;
}
/*
Room getDestination();
void setDestination(Room);
Task getTask();
void setTask();
vector<Task> getCompletedTasks();
*/

int main() {
        Robot robot1 = Robot(RobotType::mopper, RobotSize::large);
        cout << robot1.getActive() << endl;
        robot1.getBattery();
        robot1.setBrokenStatus(true);
        cout << robot1.getBrokenStatus() << endl;
}