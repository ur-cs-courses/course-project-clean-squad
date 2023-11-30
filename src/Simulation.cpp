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

Simulation::Simulation(vector<Robot> robots, vector<Room> rooms, std::vector<Task> tasks):
    allRobots(robots),
    roomList(rooms),
    taskList(tasks),
    waitingQueue(),
    cleaningRooms(),
    completeRooms()
    {
            for(int i = 0; i < robots.size(); i++) {
                availableMap[robots[i].getID()] = true;
            }
    }

std::map<int, int> dict; //map that has the <ROBOT ID , CURRENT TIME + BATTERY LIFE - 10 >
std::map<int, int> helperDict; //tester
vector<Robot> helpVector;
int id = 0;
int myTime = 0; // logical time

void Simulation::timeThread(int time) {
    while(true) {
        for(const auto& id: availableMap) {
            if(dict.find(id.first) == dict.end()) {
                dict[id.first] = myTime + this->idToRobot(id.first).getBattery() - 10;
            }
        }
        helperDict = dict;
        for(const auto& helperEntry : helperDict) {
            if(helperEntry.second == myTime) {
                availableMap[helperEntry.first] = true;
                dict.erase(helperEntry.first);
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

Simulation::~Simulation(){}

void Simulation::runSimulation(){};

Task Simulation::createTaskHelper(Room taskLocation){
    vector<Robot> taskRobots;

    if(taskLocation.getClean() != cleanStatus::dirty){
        std::cout << "This room does not need to be cleaned! \n";
        
        Task newTask(taskRobots, taskLocation);
        return newTask;
    }

    int potentialMop = 0;
    int potentialScrub = 0;
    int potentialVacuum = 0;
    int neededMop = taskLocation.getMopTime();
    int neededScrub = taskLocation.getScrubTime();
    int neededVacuum = taskLocation.getVacuumTime();

    vector<int> addedID;

    int size = allRobots.size();
    for (int i = 0; i < size; i++) {                                     //find available mop robots to add to task
        Robot addingRobot = allRobots[i];
        if(addingRobot.getRobotType() == RobotType::mopper && potentialMop < neededMop && availableMap[addingRobot.getID()] == true){
            availableMap[addingRobot.getID()] = false;
            addedID.push_back(addingRobot.getID());
            potentialMop += (addingRobot.getBattery() - 10);
        }
        else if(addingRobot.getRobotType() == RobotType::scrubber && potentialScrub < neededScrub && availableMap[addingRobot.getID()] == true){
            availableMap[addingRobot.getID()] = false;
            addedID.push_back(addingRobot.getID());
            potentialScrub += (addingRobot.getBattery() - 10);
        }
        else if(addingRobot.getRobotType() == RobotType::vacuum && potentialVacuum < neededVacuum && availableMap[addingRobot.getID()] == true){
            availableMap[addingRobot.getID()] = false;
            addedID.push_back(addingRobot.getID());
            potentialVacuum += (addingRobot.getBattery() - 10);
        }
    }

    if((potentialMop < neededMop) || (potentialScrub < neededScrub) || (potentialVacuum < neededVacuum)){      //if there's not enough robots
        std::cout << "There are not enough robots to clean this room. \n";
        for(int i = 0; i < addedID.size(); i++){
            availableMap[addedID[i]] = true;
        }
        taskRobots.clear(); 
        Task newTask(taskRobots, taskLocation);                                                                //still have to return something, but don't add to taskList
        return newTask;                                                                                   
    }

    else{
        Task newTask(taskRobots, taskLocation);                                                                //create the task and add it to taskList
        taskList.push_back(newTask);
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
    Task newTask = createTaskHelper(roomList[inputRoomID]);
}

map<int, bool> Simulation::getAvailableMap(){
    return availableMap;
}

vector<Room> Simulation::getRoomList(){
    return roomList;
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

Robot Simulation::idToRobot(int id) {
    int helper = 0;
    for(int i = 0; i < allRobots.size(); i++) {
        if(id == allRobots[i].getID()) {
            helper = i;
        }
    }
    return allRobots[helper];
}