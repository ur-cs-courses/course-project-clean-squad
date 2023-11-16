#include <string>
#include <iostream>
#include <vector>
#include "Room.hpp"
#include "Task.hpp"
#include "Robot.hpp"

using namespace std;

class Simulation {
    private:
        vector<Robot> availableRobots;
        vector<Robot> unavailableRobots;
        vector<Room> roomList; 
        vector<Room> waitingQueue;
        vector<Room> cleaningRooms;
        vector<Room> completeRooms;
    public:
        //Simulation(vector<Robot> robots,vector<Room> rooms);
        Simulation(std::vector<Robot> robots, std::vector<Room> rooms);
        ~Simulation();
        
        void runSimulation();
        //void getInput();                                           //maybe can be in main

        /*
        Task createTask(); 
        */
        vector<Robot> getAvailableRobots();
        vector<Robot> getUnavailableRobots();
        vector<Room> getRoomList();
        void printAvailableRobots();
        void printUnavailableRobots();
        void printRoomList();

};
