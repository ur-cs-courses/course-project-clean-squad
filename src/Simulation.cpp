#include "libhello/simulation.hpp"

Simulation::Simulation(vector<Robot> robots,vector<Room> rooms): 
    availableRobots(robots),
    unavailableRobots(),
    roomList(rooms),
    waitingQueue(),
    cleaningRooms(),
    completeRooms();
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

void Simulation::runSimulation();

/*
Task Simulation::createTask(){

}
*/

vector<Robot> Simulation::getAvailableRobots(){
    return availableRobots;
}

vector<Robot> Simulation::getUnavailableRobots(){
    return unavailableRobots;
}

vector<Room> Simulation::getRoomList(){
    return roomList;
}

vector<Robot> Simulation::printAvailableRobots(){
    for (int i = 0; i < availableRobots.size(); i++) {
        std::cout << "robot" << i << " size is " << availableRobots[i].getRobotSize();
        std::cout << "robot" << i << " type is " << availableRobots[i].getRobotType();
        std::cout << "\n"
    }
}

vector<Robot> Simulation::printUnavailableRobots(){
    for (int i = 0; i < unvailableRobots.size(); i++) {
        std::cout << "robot" << i << " size is " << unvailableRobots[i].getRobotSize();
        std::cout << "robot" << i << " type is " << unvailableRobots[i].getRobotType();
        std::cout << "\n"
    }
}

vector<Room> Simulation::printRoomList(){
    for (int i = 0; i < roomList.size(); i++) {
        std::cout << "room" << i << " size is " << roomList[i].getRoomSize();
        std::cout << "\n"
    }
}
