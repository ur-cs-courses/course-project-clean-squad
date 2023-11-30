#include <string>
#include <iostream>
#include <vector>
#include <functional>
#include "Room.hpp"
#include "Robot.hpp"
#include "Task.hpp"
#include <map>

using namespace std;

class Simulation {
    private:
        map<int, bool> availableMap;
        vector<Robot> allRobots; 
        vector<Room> roomList; 
        vector<Task> taskList;
        vector<Room> waitingQueue;
        vector<Room> cleaningRooms;
        vector<Room> completeRooms;
    public:
        Simulation(std::vector<Robot> robots, std::vector<Room> rooms, std::vector<Task> tasks);
        ~Simulation();
        
        void runSimulation();
        map<int, bool> getAvailableMap();
        vector<Room> getRoomList();
        void printAvailableRobots();
        void printUnavailableRobots();
        void printRoomList();
        void printTaskList();
        void createTask();
        Task createTaskHelper(Room taskLocation);
        void start();
        void timeThread(int);    
        Robot idToRobot(int);
        void setRoomsDirty();  
};
