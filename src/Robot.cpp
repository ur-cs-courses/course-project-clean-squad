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
                std::uniform_real_distribution<> distribution(0,100);
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
        }

Robot::Robot(const Robot& other) :
        isActive(false),
        isBroken(false),
        robotType(other.robotType),
        robotSize(other.robotSize),
        batteryLife(other.batteryLife),
        robotID(other.robotID),
        destination(nullptr)
        {
                std::random_device randNum;
                std::mt19937 gen(randNum());
                std::uniform_real_distribution<> distribution(0,5);
                int output = distribution(gen);
                probFailure = output;                                                              // sets probFailure to random %
        }


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

int Robot::getBattery() {
        return this->batteryLife;
}

void Robot::charge() {
        this->batteryLife = 100;
        return;
}

std::string Robot::getRobotID() const {
    return std::to_string(robotID);
}

int Robot::getID() {
        return this->robotID;
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
}

int Robot::failGrade(){                                                                            // grade of failure from 1-5 (0 = no fail)
        std::random_device randNum;
        std::mt19937 gen(randNum());
        std::uniform_real_distribution<> distribution(0,100);
        int fail = distribution(gen);

        if(this -> probFailure != 0){
                int section = this -> probFailure / 5;
                for(int i = 1; i < 6; i++){
                        if(fail < i * section){
                                std::cout << "Robot" << this -> robotID << "has had a malfunction of grade " << 6 - i;
                                return (6- i);
                                break;
                        }
                }
        }
        
        return 0;
}