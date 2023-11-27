#include <string>
#include <iostream>
#include <vector>
#include "Room.hpp"
#include "Robot.hpp"
#include "Task.hpp"

using namespace std;

class Simulation {
    private:
        vector<Robot> availableRobots;
        vector<Robot> unavailableRobots;
        vector<Room> roomList; 
        vector<Task> taskList;
        vector<Room> waitingQueue;
        vector<Room> cleaningRooms;
        vector<Room> completeRooms;
    public:
        Simulation(std::vector<Robot> robots, std::vector<Room> rooms, std::vector<Task> tasks);
        ~Simulation();
        
        void runSimulation();
        vector<Robot> getAvailableRobots();
        vector<Robot> getUnavailableRobots();
        vector<Room> getRoomList();
        void printAvailableRobots();
        void printUnavailableRobots();
        void printRoomList();
        void printTaskList();
        void createTask();
        Task createTaskHelper(Room taskLocation);

};
