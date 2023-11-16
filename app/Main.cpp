#include "libclean/Room.hpp"
#include "libclean/Robot.hpp"
#include "libclean/Task.hpp"
#include "libclean/Simulation.hpp"
#include <iostream>
#include <vector>
#include <fstream> 
 

int main() {

    int numRobots, numRooms, robotType, robotSize;
    
    vector<Robot> robots;
    vector<Room> rooms;
    int count = 0;

    // Ask the user for the number of robots
    std::cout << "Enter the number of robots: ";
    std::cin >> numRobots;


    for(int i = 0; i < numRobots; i++){
        int typeInput, sizeInput;
        RobotType typeEnum;
        RobotSize sizeEnum;
        std::cout << "\nInput for Robot " << count << std::endl;
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
        count++;
    }

    
    // Ask the user for the number of rooms
    std::cout << "\nEnter the number of rooms: ";
    std::cin >> numRooms;
    count = 0;

    for(int i = 0; i < numRooms; i++){  

        int mopTime, vacuumTime, scrubTime, sizeInput;
        RoomSize sizeEnum;

        std::cout << "\nInput for Room " << count << std::endl;

        std::cout << "Enter the mop time needed when not clean: ";
        std::cin >> mopTime;

        std::cout << "Enter the vacuum time needed when not clean: ";
        std::cin >> vacuumTime;

        std::cout << "Enter the scrub time needed when not clean: ";
        std::cin >> scrubTime;

        std::cout << "Enter the type of room (1: small, 2: medium, 3: large): ";
        std::cin >> sizeInput;

        switch (sizeInput) {
            case 1:
                sizeEnum = RoomSize::small;
                break;
            case 2:
                sizeEnum = RoomSize::medium;
                break;
            case 3:
                sizeEnum = RoomSize::large;
                break;
            default:
                std::cerr << "Invalid robot type entered.\n";
                continue;
            }

        Room newRoom(mopTime, vacuumTime, scrubTime, sizeEnum);
        rooms.push_back(newRoom);
        count++;
    }

    Simulation newSimulation(robots, rooms);

    bool simEnd = false;
    int mmInput = 0;
    std::cout << "" << std::endl;
    while(simEnd == false) {
        std::cout << "Main Menu" << std::endl;
        std::cout << "Create new task (1)" << std::endl;
        std::cout << "Print Available Robots (2)" << std::endl;
        std::cout << "Print Available Rooms (3)" << std::endl;
        std::cout << "Add Robot to Fleet (4)" << std::endl;
        std::cout << "Exit App / Simulation (5) \n" << std::endl;

        std::cout << "Enter what you would lke to do: ";
        std::cin >> mmInput;

        if (mmInput == 1) {
            std::cout << "" << std::endl;
            continue;
        }
        else if (mmInput == 2) {
            std::cout << "Here are the robots:\n";
            newSimulation.printAvailableRobots(); 
        }
        else if (mmInput == 3) {
            std::cout << "Here are the rooms:\n";
            newSimulation.printRoomList();
        }
        else if (mmInput == 4) {
            std::cout << "we should add an 'add robot' method" << std::endl;
            std::cout << "" << std::endl;
        }
        else if (mmInput == 5) {
            std::cout << "Closing Application" << std::endl;
            simEnd = true;
        }
        else {
            continue;
        }
    }

    
    //writting to csv

    std::ofstream csvFile("output.csv");

    if (!csvFile) {
        std::cerr << "Error opening output.csv for writing." << std::endl;
        return 1;
    }

    // Writing headers to the CSV file
    csvFile << "Robot Size,Robot Type,Number of Rooms,Room Size,Mop Time, Sweep Time,Scrub Time" << std::endl;
    for (const auto& robot : robots) {
        csvFile << "medium" << "," << "mopper" <<  "," << rooms.size() <<  "," << "small"<<  "," <<45  << "," << 20 << "," << 15 << std::endl;
   
}


    csvFile.close();

return 0;
}


    








