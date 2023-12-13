//Robot Class File
#include "libclean/Robot.hpp"
#include "libclean/Room.hpp" 
#include <iostream>
#include <random>

using namespace std;

int Robot::nextRobotID = 0;
Robot::Robot(RobotType type, RobotSize size) :
        isActive(false),
        isBroken(false),
        robotType(type),
        robotSize(size),
        robotID(nextRobotID++),
        destination(nullptr)
        {
                std::random_device randNum;
                std::mt19937 gen(randNum());
                std::uniform_real_distribution<> distribution(0,5);
                int output = distribution(gen);
                probFailure = output;                                                              // sets probFailure to random %

                if(size == RobotSize::small) {
                        batteryLife = 50;
                } else if(size == RobotSize::medium) {
                        batteryLife = 100;
                } else if (size == RobotSize::large) {
                        batteryLife = 200;
                } else {
                        batteryLife = 0;
                }
                taskDuration = 0;
        }

Robot::Robot(const Robot& other) :
        isActive(false),
        isBroken(false),
        robotType(other.robotType),
        robotSize(other.robotSize),
        batteryLife(other.batteryLife),
        taskDuration(other.taskDuration),
        robotID(other.robotID),
        destination(nullptr),
        probFailure(other.probFailure)
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

RobotType Robot::getRobotType() const{
        return this->robotType;
}

RobotSize Robot::getRobotSize() const{
        return this->robotSize;
}

int Robot::getTaskDuration() {
        return this->taskDuration;
}

void Robot::setTaskDuration(int taskTime) {
        if(this->robotSize == RobotSize::small) {
                if(taskTime > this->getBattery()){
                        this->taskDuration = this->getBattery() - 10;
                }else{
                        this->taskDuration = taskTime;
                }
        }     
        if(this->robotSize == RobotSize::medium) {
                if(taskTime > this->getBattery()){
                        this->taskDuration = this->getBattery() - 10;
                }
                else{
                        this->taskDuration = taskTime;
                }
        }
       if(this->robotSize == RobotSize::large) {
                if(taskTime > this->getBattery()){
                        this->taskDuration = this->getBattery() - 10;
                }else{
                        this->taskDuration = taskTime;
                }
        }
        return;
}

int Robot::getBattery() {
        return this->batteryLife;
}

void Robot::charge() {
       if(robotSize == RobotSize::small) {
                this -> batteryLife = 50;
        } else if(robotSize == RobotSize::medium) {
                this -> batteryLife = 100;
        } else if (robotSize == RobotSize::large) {
                this -> batteryLife = 200;
        }
        else{ 
                this -> batteryLife = 0;
        }
        return;
}

// methods to add robots stuffs to the database
std::string Robot::getRobotID() const {
    return std::to_string(robotID);
}

std::string Robot::getRobotBattery() const {
    return std::to_string(batteryLife);
}

std::string Robot::getProbFailureString() const {
    return std::to_string(probFailure);
}



int Robot::getID() {
        return this->robotID;
}

void Robot::updateBattery(int amountTime) {
    if (this->batteryLife > 0) {
        this->batteryLife -= amountTime;
    } else {
        this->batteryLife = 0;
        setBrokenStatus(true);
    }
    return;
}

void Robot::printRobot() {                                                                         //prints ID, size, type, and failure probability
        string size  = "";
        string type = "";

        if(this->robotSize == RobotSize::small) {size = "small";}
                else if(this->robotSize == RobotSize::medium) {size = "medium";}
                else if(this->robotSize == RobotSize::large) {size = "large";}

        if(this->robotType == RobotType::mopper) {type = "mopper";}
                else if(this->robotType == RobotType::scrubber) {type = "scrubber";}
                else if(this->robotType == RobotType::vacuum) {type = "vacuum";}

        std::cout << "Robot ID: " << robotID << std::endl;
        std::cout << "Robot Size: " << size << std::endl;
        std::cout << "Robot Type: " << type << std::endl;
        std::cout << "Prob Failure: " << probFailure << std::endl;
        std::cout << "Battery Remain: " << batteryLife << std::endl;
}

int Robot::failGrade(){                                                                            // grade of failure from 1-5 (0 = no fail)
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distribution100(0, 100);                                //chance of if it fails or not
        int failChance = distribution100(gen);
        std::uniform_int_distribution<int> distribution5(0, 5);                                    //grade of failure if it does fail
        int gradeOfFail = distribution5(gen);

        if(failChance < this -> probFailure){
                return gradeOfFail;
        }
        
        return 0;
}
