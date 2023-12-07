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
        map<int, vector<bool>> taskMap;
        vector<Robot> allRobots; 
        vector<Room> roomList; 
        vector<Task> taskList;
        vector<Room> waitingQueue;
        vector<Room> cleaningRooms;
        vector<Room> completeRooms;
        vector<bool> helperBool;
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
        const std::vector<Task>& getTasks() const;
        void createTask();
        Task createTaskHelper(Room taskLocation);
        void start();
        void timeThread(int);    
        Robot idToRobot(int);
        Room idToRoom(int);
        void setRoomsDirty();  
        void setRoomDNC(int);
};
