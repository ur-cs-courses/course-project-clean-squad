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

    int numRobots, numRooms, robotType, robotSize, numTasks, choice;
    
    vector<Robot> robots;
    vector<Room> rooms;
    vector<Task> tasks;
    int count = 0;

    //Ask for custom or default
    std::cout << "Would you like to use the default simulator or create a custom simulator (1: default, 2: custom): ";
    std::cin >> choice;

    if (choice == 2){
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

        Room newRoom(RoomSize::home);
        rooms.push_back(newRoom);

        for(int i = 0; i < numRooms; i++){  

            int sizeInput;
            RoomSize sizeEnum;

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
                    std::cerr << "Invalid room type entered.\n";
                    continue;
                }

            Room newRoom(sizeEnum);

            std::cout <<"Would you like to prevent the robots from cleaning this room? (1: yes)" ;
            std::cin >> sizeInput;
            if(sizeInput == 1){
                newRoom.setClean(cleanStatus::doNotClean);
            }

            rooms.push_back(newRoom);
            count++;
        }

    }
    
    else{
        std::cout << "Here is the default simulator.";
        numRobots = 13;

        Robot newRobot1(RobotType::mopper, RobotSize::small);                                       //robot 1
        robots.push_back(newRobot1);
        Robot newRobot2(RobotType::mopper, RobotSize::medium);                                      //robot 2
        robots.push_back(newRobot2);
        Robot newRobot3(RobotType::mopper, RobotSize::large);                                       //robot 3
        robots.push_back(newRobot3);
        Robot newRobot4(RobotType::vacuum, RobotSize::small);                                        //robot 4
        robots.push_back(newRobot4);
        Robot newRobot5(RobotType::vacuum, RobotSize::medium);                                       //robot 5
        robots.push_back(newRobot5);
        Robot newRobot6(RobotType::vacuum, RobotSize::large);                                        //robot 6
        robots.push_back(newRobot6);
        Robot newRobot7(RobotType::scrubber, RobotSize::small);                                      //robot 7
        robots.push_back(newRobot7);
        Robot newRobot8(RobotType::scrubber, RobotSize::medium);                                     //robot 8
        robots.push_back(newRobot8);
        Robot newRobot9(RobotType::scrubber, RobotSize::large);                                      //robot 9
        robots.push_back(newRobot9);
        Robot newRobot0(RobotType::scrubber, RobotSize::medium);                                     //robot 10
        robots.push_back(newRobot0);
        Robot newRobot11(RobotType::mopper, RobotSize::large);                                        //robot 11
        robots.push_back(newRobot11);
        Robot newRobot12(RobotType::vacuum, RobotSize::small);                                        //robot 12
        robots.push_back(newRobot12);
        Robot newRobot13(RobotType::vacuum, RobotSize::small);                                        //robot 13
        robots.push_back(newRobot13);
       
        numRooms = 6;

        Room newRoom(RoomSize::home);
        rooms.push_back(newRoom);

        Room newRoom1(RoomSize::small);                                                            //room 1
        rooms.push_back(newRoom1);
        Room newRoom2(RoomSize::small);                                                            //room 2
        rooms.push_back(newRoom2);
        Room newRoom3(RoomSize::medium);                                                           //room 3 (do not clean)
        newRoom3.setClean(cleanStatus::doNotClean);
        rooms.push_back(newRoom3);
        Room newRoom4(RoomSize::medium);                                                           //room 4
        rooms.push_back(newRoom4);
        Room newRoom5(RoomSize::large);                                                            //room 5
        rooms.push_back(newRoom5);
        Room newRoom6(RoomSize::large);                                                            //room 6
        rooms.push_back(newRoom6);
    }    
    
    Simulation newSimulation(robots, rooms, tasks);

// Write initial state to CSV
writeToCSV(robots, rooms, "output.csv");
bool simEnd = false;
int mmInput = 0;

newSimulation.start();

std::cout << "" << std::endl;
do {
    //will be updating the csv file after every operation that modifies room,robots, or tasks by just calling
    //writeToCSV(robots, rooms, "output.csv");
    std::cout << "Main Menu" << std::endl;
    std::cout << "Create new task (1)" << std::endl;
    std::cout << "Print Available Robots (2)" << std::endl;
    std::cout << "Print Available Rooms (3)" << std::endl;
    std::cout << "Add Robot to Fleet (4)" << std::endl;
    std::cout << "Make all clean rooms dirty (5)" << std::endl;
    std::cout << "Exit App / Simulation (6)" << std::endl;
    std::cout << "Enter what you would like to do: ";
    std::cin >> mmInput;

    std::cout << "\n";

    if(std::cin.fail()) {
        std::cin.clear(); // Clears the error flags
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discards the input buffer
        std::cout << "Invalid input, please choose from the displayed options." << std::endl;
        continue;
    }

    switch(mmInput) {
        case 1:
            std::cout << "Task creation:" << std::endl;
            newSimulation.createTask();
            newSimulation.printTaskList();
            break;
        case 2:
            std::cout << "Here are the robots:\n" << std::endl;
            newSimulation.printAvailableRobots(); 
            break;
        case 3:
            std::cout << "Here are the rooms:\n" << std::endl;
            newSimulation.printRoomList();
            break;
        case 4:
            std::cout << "we should add an 'add robot' method" << std::endl;
            std::cout << "" << std::endl;
            break;
        case 5:
            newSimulation.setRoomsDirty();
            break;
        case 6:
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
