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
    availableRobots(robots),
    unavailableRobots(),
    roomList(rooms),
    taskList(tasks),
    waitingQueue(),
    cleaningRooms(),
    completeRooms()
{}

std::map<int, int> dict; //map that has the <ROBOT ID , CURRENT TIME + BATTERY LIFE - 10 >
std::map<int, int> helperDict; //tester
vector<Robot> helpVector;
int id = 0;
int myTime = 0; // logical time

void Simulation::timeThread(int time) {
    while(true) {
        vector<Robot> helper = this->getUnavailableRobots(); //this needs to be unavailable robots but cannot test that
        for(int i = 0; i < helper.size(); i++) {
            id = helper[i].getID();
            if(dict.find(id) == dict.end()) {
                dict[id] = myTime + helper[i].getBattery() - 10;
            }
        }
        helperDict = dict;
        for(const auto& entry: helperDict) {
            if(entry.second == myTime) {
                helpVector = unavailableRobots;
                for(int q = 0; q < helpVector.size(); q++) {
                    Robot tRobot = helpVector[q];
                    if(tRobot.getID() == entry.first) {
                        availableRobots.push_back(tRobot);     //move mop robot from available to unavailable    
                        this->unavailableRobots.erase(this->unavailableRobots.begin() + q);
                        dict.erase(entry.first);
                    }
                }
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

    if(taskLocation.getClean()){
        std::cout << "This room is already clean!\n";
        
        Task newTask(taskRobots, taskLocation);
        return newTask;
    }

    int potentialMop = 0;
    int potentialScrub = 0;
    int potentialVacuum = 0;
    int neededMop = taskLocation.getMopTime();
    int neededScrub = taskLocation.getScrubTime();
    int neededVacuum = taskLocation.getVacuumTime();

    for (int i = 0; i < availableRobots.size(); i++) {                                     //find available mop robots to add to task
        Robot addingRobot = availableRobots[i];
        if(addingRobot.getRobotType() == RobotType::mopper){
            std::cout<< "Mopper robot added!\n";
            taskRobots.push_back(addingRobot);

            unavailableRobots.push_back(addingRobot);                                      //move mop robot from available to unavailable
            this->availableRobots.erase(availableRobots.begin() + i);

            potentialMop += (addingRobot.getBattery() - 10);
        }

        if (potentialMop >= neededMop){
            break;
        }
    }

    for (int i = 0; i < availableRobots.size(); i++) {                                     //find available scrubber robots to add to task
        Robot addingRobot = availableRobots[i];
        if(addingRobot.getRobotType() == RobotType::scrubber){
            std::cout<< "Scrubber robot added!\n";
            taskRobots.push_back(addingRobot);

            unavailableRobots.push_back(addingRobot);                                      //move scrubber robot from available to unavailable
            this->availableRobots.erase(availableRobots.begin() + i);

            potentialScrub += (addingRobot.getBattery() - 10);

            if (potentialScrub >= neededScrub){
                break;
            }
        }
    }
    //throw std::runtime_error("Failed to create a valid task"); //throws an error message when there are paths that do not hit the return inside the while loop

    for (int i = 0; i < availableRobots.size(); i++) {                                     //find available vacuum robots to add to task
        Robot addingRobot = availableRobots[i];
        if(addingRobot.getRobotType() == RobotType::vacuum){
            std::cout<< "Vacuum robot added!\n";
            taskRobots.push_back(addingRobot);

            unavailableRobots.push_back(addingRobot);                                      //move vacuum robot from available to unavailable
            this->availableRobots.erase(availableRobots.begin() + i);

            potentialVacuum += (addingRobot.getBattery() - 10);

            if (potentialVacuum >= neededVacuum){
                break;
            }
        }
    }

    if((potentialMop < neededMop) || (potentialScrub < neededScrub) || (potentialVacuum < neededVacuum)){      //if there's not enough robots
        std::cout << "There are not enough robots to clean this room. \n";
        for(int i = 0; i < taskRobots.size(); i++){
            unavailableRobots.push_back(availableRobots.back());                                               //put all the robots back in the correct vector         
            availableRobots.pop_back();
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

vector<Robot> Simulation::getAvailableRobots(){
    return availableRobots;
}

vector<Robot> Simulation::getUnavailableRobots(){
    return unavailableRobots;
}

vector<Room> Simulation::getRoomList(){
    return roomList;
}

void Simulation::printAvailableRobots(){
    for (int i = 0; i < availableRobots.size(); i++) {
        availableRobots[i].printRobot();
        std::cout << "\n";
    }
}

void Simulation::printUnavailableRobots(){
    for (int i = 0; i < unavailableRobots.size(); i++) {
        unavailableRobots[i].printRobot();
        std::cout << "\n";
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
