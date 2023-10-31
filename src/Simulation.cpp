#include "libhello/simulation.hpp"

Simulation::Simulation(vector<Robot> robots,vector<Room> rooms): 
    availableRobots(robots),
    unavailableRobots(),
    roomList(rooms),
    waitingQueue(),
    cleaningRooms(),
    completeRooms();
{}

Simulation::~Simulation(){}

void Simulation::runSimulation();
void Simulation::getInput();                                           //maybe can be in main

/*
Task Simulation::createTask(){

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
*/
