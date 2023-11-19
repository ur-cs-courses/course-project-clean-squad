#include "libclean/Simulation.hpp"
#include "libclean/Room.hpp"
#include "libclean/Robot.hpp"
#include "libclean/Task.hpp"
#include <fmt/core.h>

Simulation::Simulation(vector<Robot> robots, vector<Room> rooms, std::vector<Task> tasks): 
    availableRobots(robots),
    unavailableRobots(robots),
    roomList(rooms),
    taskList(tasks),
    waitingQueue(),
    cleaningRooms(),
    completeRooms()
{}

/*
Simulation::Simulation(): 
    unavailableRobots(),
    waitingQueue(),
    cleaningRooms(),
    completeRooms();
{
    int check = 1;
    int type = size = 0;
    while(check != 0){
        cout << "Press 0 to stop adding robots. Press any other key to add a robot.";
        cin >> check;

        cout << "What type of robot is it?";
        cin >> type;

        cout << "What is the size of the robot?";
        cin >> size;

        Robot newRobot(type, size);
        availableRobots.push_back(newRobot);
    }

    check = 1;

    while(check != 0){
        cout << "Press 0 to stop adding rooms. Press any other key to add a room.";
        cin >> check;

        Room newRoom();
        availableRobots.push_back(newRoom);
    }

}
*/

Simulation::~Simulation(){}

void Simulation::runSimulation(){};

Task Simulation::createTaskHelper(Room taskLocation){
    int potentialMop = 0;
    int potentialScrub = 0;
    int potentialVacuum = 0;
    int neededMop = taskLocation.getMopTime();
    int neededScrub = taskLocation.getScrubTime();
    int neededVacuum = taskLocation.getVacuumTime();
    vector<Robot> taskRobots;

    while((potentialMop < neededMop) && (potentialScrub < neededScrub) && (potentialVacuum < neededVacuum)){
        int newRobot;
        std::cout << "What kind of robot would you like to add? (1: mopper, 2: vacuum, 3: scrubber): ";
        std::cin >> newRobot;

        switch (newRobot) {
        case 1:
            for (int i = 0; i < availableRobots.size(); i++) {                                     //find an available mop robot to add to task
                Robot addingRobot = availableRobots[i];
                if(addingRobot.getRobotType() == RobotType::mopper){
                    cout<< "Mopper robot added!\n";
                    taskRobots.push_back(addingRobot);

                    unavailableRobots.push_back(addingRobot);                                      //move mop robot from available to unavailable
                    this->availableRobots.erase(availableRobots.begin() + i);

                    potentialMop += (addingRobot.getBattery() - 10);
                    break;
                }
            }
            break;

        case 2:
            for (int i = 0; i < availableRobots.size(); i++) {                                     //find an available mop robot to add to task
                Robot addingRobot = availableRobots[i];
                if(addingRobot.getRobotType() == RobotType::scrubber){
                    cout<< "Scrubber robot added!\n";
                    taskRobots.push_back(addingRobot);

                    unavailableRobots.push_back(addingRobot);                                      //move mop robot from available to unavailable
                    this->availableRobots.erase(availableRobots.begin() + i);

                    potentialScrub += (addingRobot.getBattery() - 10);
                    break;
                }
            }
            break;

        case 3:
            for (int i = 0; i < availableRobots.size(); i++) {                                     //find an available mop robot to add to task
                Robot addingRobot = availableRobots[i];
                if(addingRobot.getRobotType() == RobotType::vacuum){
                    cout<< "Vacuum robot added!\n";
                    taskRobots.push_back(addingRobot);

                    unavailableRobots.push_back(addingRobot);                                      //move mop robot from available to unavailable
                    this->availableRobots.erase(availableRobots.begin() + i);

                    potentialVacuum += (addingRobot.getBattery() - 10);
                    break;
                }
            }
            break;
        default:
            std::cout << "Invalid choice." << std::endl;

        std::cout << "There is still" << neededMop - potentialMop << " time left for Mopping, " 
            << neededScrub - potentialScrub << " time left for scrubbing, and " << neededVacuum - potentialVacuum 
            << " time left for sweeping.";
    }

    Task newTask(taskRobots, taskLocation);
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