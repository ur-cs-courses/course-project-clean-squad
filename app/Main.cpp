#include "libclean/Room.hpp"
#include "libclean/Robot.hpp"
#include "libclean/Task.hpp"
#include "libclean/Simulation.hpp"
#include <iostream>
#include <vector>

int main() {

    int numRobots, numRooms, robotType, robotSize;
    
    vector<Robot> robots;
    vector<Room> rooms;

    // Ask the user for the number of robots
    std::cout << "Enter the number of robots: ";
    std::cin >> numRobots;

    /*
    for(int i = 0; i < numRobots; i++){
        std::cout << "What type of robot would you like to add";
        std::cin >> robotType;
        RobotType typeEnum = static_cast<RobotType>(robotType);

        std::cout << "What size robot would you like to add";
        std::cin >> robotSize;
        RobotSize sizeEnum = static_cast<RobotSize>(robotSize);
        
        Robot newRobot(typeEnum, sizeEnum);
        robots.push_back(newRobot);
    }
    */

    for(int i = 0; i < numRobots; i++){
        int typeInput, sizeInput;
        RobotType typeEnum;
        RobotSize sizeEnum;

        std::cout << "Enter the type of robot (1: mopper, 2: sweeper, 3: scrubber): ";
        std::cin >> typeInput;

        switch (typeInput) {
            case 1:
                typeEnum = RobotType::mopper;
                break;
            case 2:
                typeEnum = RobotType::sweeper;
                break;
            case 3:
                typeEnum = RobotType::scrubber;
                break;
            default:
                std::cerr << "Invalid robot type entered.\n";
                continue;
            }

        std::cout << "Enter the size of robot (1: small, 2: medium, 3: large): ";
        std::cin >> sizeInput;

        switch (sizeInput) {
            case 1:
                sizeEnum = RobotSize::small;
                break;
            case 2:
                sizeEnum = RobotSize::medium;
                break;
            case 3:
                sizeEnum = RobotSize::large;
                break;
            default:
                std::cerr << "Invalid robot size entered.\n";
                continue;
            }

        Robot newRobot(typeEnum, sizeEnum);
        robots.push_back(newRobot);
    }

    
    // Ask the user for the number of rooms
    std::cout << "Enter the number of rooms: ";
    std::cin >> numRooms;

    for(int i = 0; i < numRooms; i++){      
        Room newRoom;
        rooms.push_back(newRoom);
    }

    Simulation newSimulation(robots, rooms);


    std::cout << "Here are the robots:\n";
    newSimulation.printAvailableRobots(); 

    std::cout << "Here are the rooms:\n";
    newSimulation.printRoomList();

    
    /*
    Task myTask;
    myTask.setNumRobots(20); 
    int numberOfRobots = myTask.getNumRobots();
    std::cout << "Number of robots: " << numberOfRobots << std::endl;
    */
    
    return 0;
}
