#include "simulation.hpp"
#include "room.hpp"
#include "Robot.hpp"
#include <iostream>

int main() {
    int numRobots, numRooms, robotType, robotSize;
    
    vector<Robot> robots;
    vector<Room> rooms;

    // Ask the user for the number of robots
    std::cout << "Enter the number of robots: ";
    std::cin >> numRobots;

    for(int i = 0; i < numRobots; i++){
        std::cout << "What type of robot would you like to add";
        std::cin >> robotType;

        std::cout << "What size robot would you like to add";
        std::cin >> robotSize;
        
        Robot newRobot(robotType, robotSize);
        robots.push(newRobot);
    }

    // Ask the user for the number of rooms
    std::cout << "Enter the number of rooms: ";
    std::cin >> numRooms;

    for(int i = 0; i < numRobots; i++){      
        Room newRoom();
        rooms.push(newRoom);
    }

    Simulation newSimulation(robots, rooms);

    //need to add print overload for room and robot classes

    std::cout << "Here are the robots." << newSimulation.printAvailableRobots;
    std::cout << "Here are the rooms." << newSimulation.printRoomList;
    
    return 0;
}
