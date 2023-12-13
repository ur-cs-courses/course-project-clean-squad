#include "libclean/Simulation.hpp"
#include "libclean/Room.hpp"
#include "libclean/Robot.hpp"
#include "libclean/Task.hpp"
#include <fmt/core.h>
#include <stdexcept> //for runtime_error
#include <map>
#include <thread>
#include <iostream>
#include <cstdlib>
#include <mutex>

Simulation::Simulation(vector<Robot> robots, vector<Room> rooms, std::vector<Task> tasks):
    allRobots(robots),
    roomList(rooms),
    taskList(tasks),
    waitingQueue(),
    cleaningRooms(),
    helperBool(robots.size()),
    completeRooms()
    {
            for(int i = 0; i < robots.size(); i++) {
                availableMap[robots[i].getID()] = true;
            }
            for(int i = 0; i < robots.size(); i++) {
                helperBool[i] = false;
            }
            taskMap[0] = helperBool;
    }

std::map<int, int> dict; //map that has the <ROBOT ID , CURRENT TIME + BATTERY LIFE - 10 >
std::map<int, int> helperDict; //tester
std::map<int, vector<bool>> helperTaskDict;
std::vector<Robot> helperVect;
std::vector<Task> helperTasks;
int myTime = 0; // logical time

std::mutex taskListMutex;

void Simulation::timeThread(int time) {
    while(true) {
        for(const auto& entry : availableMap) {
            if(dict.find(entry.first) == dict.end() && entry.second == false) {
                dict[entry.first] = myTime + this->idToRobot(entry.first).getBattery() - 10;
            }
        }
        helperDict = dict;
        for(const auto& helperEntry : helperDict) {
            if(helperEntry.second == myTime) {
                availableMap[helperEntry.first] = true;
                dict.erase(helperEntry.first);
            }
        }

        bool done = false;
        helperTaskDict = taskMap;
        for(auto& task : helperTaskDict) {
            done = true;
            for(int i = 0; i < task.second.size(); i++) {
                if(task.second[i] == true && dict.find(i) == dict.end()) {
                    task.second[i] = false;
                }
                else if(task.second[i] == true && dict.find(i) != dict.end()) {
                    done = false;
                }
            }
            if(done == true) {
                roomList[task.first].setClean(cleanStatus::clean);

                std::unique_lock<std::mutex> lock(taskListMutex);
                for(int i = 0; i < taskList.size(); i++) {
                    if(taskList[i].getRoomID() == task.first) {
                        taskList[i].setIsCompleted(true);
                    }
                }
                lock.unlock();

                taskMap.erase(task.first);
            }
        }
        
        
        myTime = myTime + 10;
        //std::cout << myTime << std::endl;
        std::system("sleep 1");
    }
}

std::thread time_thread;
void Simulation::start() {
    time_thread = std::thread(std::bind(&Simulation::timeThread, this, 10));
}

Simulation::~Simulation() {
    for (auto& thread : chargingThreads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
}

void Simulation::runSimulation(){};

Task Simulation::createTaskHelper(Room taskLocation){
    vector<Robot> taskRobots;

    if(taskLocation.getClean() != cleanStatus::dirty){
        std::cout << "This room does not need to be cleaned! \n";
        
        Task newTask;
        return newTask;
    }

    int potentialMop = 0;
    int potentialScrub = 0;
    int potentialVacuum = 0;
    int neededMop = taskLocation.getMopTime();
    int neededScrub = taskLocation.getScrubTime();
    int neededVacuum = taskLocation.getVacuumTime();
    int currMop = neededMop;
    int currScrub = neededScrub;
    int currVacuum = neededVacuum;

    vector<int> addedID;

    int size = allRobots.size();
    for (int i = 0; i < size; i++) {                                     //find available mop robots to add to task
        Robot& addingRobot = allRobots[i];
        if(addingRobot.getRobotType() == RobotType::mopper && potentialMop < neededMop && availableMap[addingRobot.getID()] == true && addingRobot.getBattery() >= 20){
            availableMap[addingRobot.getID()] = false;
            addedID.push_back(addingRobot.getID());
            potentialMop += (addingRobot.getBattery() - 10);
            addingRobot.setTaskDuration(currMop);
            currMop -= addingRobot.getTaskDuration();
            taskRobots.push_back(addingRobot);
        }
        else if(addingRobot.getRobotType() == RobotType::scrubber && potentialScrub < neededScrub && availableMap[addingRobot.getID()] == true && addingRobot.getBattery() >= 20){
            availableMap[addingRobot.getID()] = false;
            addedID.push_back(addingRobot.getID());
            potentialScrub += (addingRobot.getBattery() - 10);
            addingRobot.setTaskDuration(currScrub);
            currScrub -= addingRobot.getTaskDuration();
            taskRobots.push_back(addingRobot);
        }
        else if(addingRobot.getRobotType() == RobotType::vacuum && potentialVacuum < neededVacuum && availableMap[addingRobot.getID()] == true && addingRobot.getBattery() >= 20){
            availableMap[addingRobot.getID()] = false;
            addedID.push_back(addingRobot.getID());
            potentialVacuum += (addingRobot.getBattery() - 10);
            addingRobot.setTaskDuration(currVacuum);
            currVacuum -= addingRobot.getTaskDuration();
            taskRobots.push_back(addingRobot);
        }
    }

    if((potentialMop < neededMop) || (potentialScrub < neededScrub) || (potentialVacuum < neededVacuum)){      //if there's not enough robots
        std::cout << "There are not enough robots to clean this room. \n";
        for(int i = 0; i < addedID.size(); i++){
            availableMap[addedID[i]] = true;
        }
        Task newTask;                                                                //still have to return something, but don't add to taskList
        return newTask;                                                                                   
    }

    else {
        Task newTask(taskRobots, taskLocation);                                                                //create the task and add it to taskList
        roomList[taskLocation.getID()].setClean(cleanStatus::cleaning);

        std::unique_lock<std::mutex> lock(taskListMutex);
        taskList.push_back(newTask);
        lock.unlock();
        
        std::cout << newTask.getID() << std::endl;
        for(int i = 0; i < taskRobots.size(); i++) {
            helperBool[taskRobots[i].getID()] = true;
        }
        taskMap[taskLocation.getID()] = helperBool;
        return newTask;
    }
}

void Simulation::createTask(){
    int inputRoomID;
    if (roomList.empty()){
        std::cout << "You need to have a room for robot destination!" << std::endl;
    }
    std::cout << "Enter the ID for room to clean: ";
    std::cin >> inputRoomID;

    if (inputRoomID < 0 || inputRoomID >= roomList.size()) {
        std::cout << "Invalid room ID." << std::endl;
        return;
    }
    Task newTask = createTaskHelper(roomList[inputRoomID]);
}

map<int, bool> Simulation::getAvailableMap(){
    return availableMap;
}

vector<Room> Simulation::getRoomList(){
    return roomList;
}

// Getter for the task list
const std::vector<Task>& Simulation::getTasks() const {
    return taskList;
}

void Simulation::printAvailableRobots(){
    for (const auto& entry: this->availableMap) {
        if(entry.second == true) {
            this->idToRobot(entry.first).printRobot();
            std::cout << "\n";
        }
    }
}

void Simulation::printUnavailableRobots(){
    for (const auto& entry: this->availableMap) {
        if(entry.second == false) {
            this->idToRobot(entry.first).printRobot();
            std::cout << "\n";
        }
    }
}

void Simulation::printRoomList(){
    for (int i = 0; i < roomList.size(); i++) {
        roomList[i].printRoom();
        std::cout << "\n";
    }
}

void Simulation::printTaskList(){
    for (int i = 0; i < taskList.size(); i++) {
        taskList[i].printTask();
        std::cout << "\n";
    }
}

void Simulation::setRoomsDirty() {
    for(int i = 0; i < roomList.size(); i++) {
        if(roomList[i].getClean() == cleanStatus::clean) {
            roomList[i].setClean(cleanStatus::dirty);
        }
    }
}

void Simulation::setRoomDNC(int id) {
    bool helper = false;
    for (int i = 0; i < roomList.size(); i++) {
        if(roomList[id].getID() == id) {
            roomList[id].setClean(cleanStatus::doNotClean);
            helper = true;
        }
    }
    if(helper == false) {
        std::cout << "Invalid RoomID \n" << std::endl;
    }
    else {
        std::cout << "Room " << id << " is set to DO NOT CLEAN \n" << std::endl;
    }
}

Robot Simulation::idToRobot(int id) {
    int helper = 0;
    for(int i = 0; i < allRobots.size(); i++) {
        if(id == allRobots[i].getID()) {
            helper = i;
        }
    }
    return allRobots[helper];
}

Room Simulation::idToRoom(int id) {
    int helper = 0;
    for(int i = 0; i < roomList.size(); i++) {
        if(id == roomList[i].getID()) {
            helper = i;
        }
    }
    return roomList[helper];
}

void Simulation::updateRobotBattery(){
    int size = allRobots.size();
    for (int i = 0; i < size; i++) { 
        Robot& updatingRobot = allRobots[i];
        if(updatingRobot.getTaskDuration() != 0) {
            updatingRobot.updateBattery(updatingRobot.getTaskDuration() + 10);
            updatingRobot.setTaskDuration(0);
        }
    }
}

void Simulation::chargeIndividual(Robot& robot){
    int maxBattery{0};
    if(robot.getRobotSize() == RobotSize::small) {
        maxBattery = 50;
        }     
    if(robot.getRobotSize() == RobotSize::medium) {
        maxBattery = 100;
        }
    if(robot.getRobotSize() == RobotSize::large) {
        maxBattery = 200;
        }
    while (robot.getBattery() < maxBattery) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        robot.updateBattery(-10);
    }
    robot.charge();
}

void Simulation::chargeRobots(){
    int size = allRobots.size();
    for (int i = 0; i < size; i++) {
        Robot& robot = allRobots[i];
        int maxBattery{0};
        if(robot.getRobotSize() == RobotSize::small) {
            maxBattery = 50;
        }     
        if(robot.getRobotSize() == RobotSize::medium) {
            maxBattery = 100;
        }
        if(robot.getRobotSize() == RobotSize::large) {
            maxBattery = 200;
        }
        if (robot.getBattery() < maxBattery) {
            chargingThreads.push_back(std::thread(&Simulation::chargeIndividual, this, std::ref(robot)));
        }
    }
}
