#include "libclean/Room.hpp"
#include "libclean/Robot.hpp"
#include "libclean/Task.hpp"
#include "libclean/Simulation.hpp"
#include <iostream>
#include <vector>
#include <fstream> 

void writeToCSV(const std::vector<Robot>& robots, const std::vector<Room>& rooms, const std::string& filename) {
    std::ofstream csvFile(filename, std::ofstream::trunc);  // Open in truncate mode to overwrite existing contents

    if (!csvFile) {
        std::cerr << "Error opening " << filename << " for writing." << std::endl;
        return;
    }

     // Writing headers to the CSV file for Robots
    csvFile << "Robot ID,Robot Type,Robot Size\n";

    // Write robot details to the CSV
    for (const auto& robot : robots) {
        csvFile << robot.getRobotID() << ","
                << robot.getRobotTypeString() << ","
                << robot.getRobotSizeString()<< "\n";
    }

    // Writing headers to the CSV file for Rooms
    csvFile << "\nRoom ID,Mop Time,Sweep Time,Scrub Time\n";

    // Write room details to the CSV
    for (size_t i = 0; i < rooms.size(); ++i) {
        csvFile << i << ","  // Assuming room ID is its index in the room vector
                << rooms[i].getMopTime() << ","
                << rooms[i].getVacuumTime() << ","
                << rooms[i].getScrubTime() << "\n";
    }

    
    csvFile.close();
}

 

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
        std::cout << "Enter the type of robot (1: mopper, 2: vacuum, 3: scrubber): ";
        std::cin >> typeInput;

        switch (typeInput) {
            case 1:
                typeEnum = RobotType::mopper;
                break;
            case 2:
                typeEnum = RobotType::vacuum;
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

        int mopTime, sweepTime, scrubTime, sizeInput;
        RoomSize sizeEnum;

        std::cout << "\nInput for Room " << count << std::endl;

        std::cout << "Enter the mop time needed when not clean: ";
        std::cin >> mopTime;

        std::cout << "Enter the vacuum time needed when not clean: ";
        std::cin >> sweepTime;

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

        Room newRoom(mopTime, sweepTime, scrubTime, sizeEnum);
        rooms.push_back(newRoom);
        count++;
    }

    Simulation newSimulation(robots, rooms);

// Write initial state to CSV
writeToCSV(robots, rooms, "output.csv");
bool simEnd = false;
int mmInput = 0;

do {
    //will be updating the csv file after every operation that modifies room,robots, or tasks by just calling
    //writeToCSV(robots, rooms, "output.csv");
    std::cout << "" << std::endl;
    std::cout << "Main Menu" << std::endl;
    std::cout << "Create new task (1)" << std::endl;
    std::cout << "Print Available Robots (2)" << std::endl;
    std::cout << "Print Available Rooms (3)" << std::endl;
    std::cout << "Add Robot to Fleet (4)" << std::endl;
    std::cout << "Exit App / Simulation (5)" << std::endl;
    std::cout << "Enter what you would like to do: ";
    std::cin >> mmInput;

    if(std::cin.fail()) {
        std::cin.clear(); // Clears the error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discards the input buffer
        std::cout << "Invalid input, please choose from the displayed options." << std::endl;
        continue;
    }

    switch(mmInput) {
        case 1:
            std::cout << "Task simulation is coming" << std::endl;
            //task stuffs
            break;
        case 2:
            std::cout << "Here are the robots:\n";
            newSimulation.printAvailableRobots(); 
            break;
        case 3:
            std::cout << "Here are the rooms:\n";
            newSimulation.printRoomList();
            break;
        case 4:
            std::cout << "we should add an 'add robot' method" << std::endl;
            std::cout << "" << std::endl;
            break;
        case 5:
            std::cout << "Closing Application" << std::endl;
            simEnd = true;
            break;
        default:
            std::cout << "Invalid option. Please enter a number between 1 and 5." << std::endl;
            break;
    }
} while(!simEnd);

return 0;
}


    








