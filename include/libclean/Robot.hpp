#ifndef LIBCLEAN_ROBOT_HPP
#define LIBCLEAN_ROBOT_HPP

#include <string>
#include <vector>
//#include "Room.hpp"
//#include "Task.hpp"


using namespace std;

enum class RobotType {mopper, sweeper, scrubber};
enum class RobotSize {small, medium, large};

class Robot {

    private:
        static int nextRobotID;
        bool        isActive;
        bool        isBroken;
        RobotType   robotType;
        RobotSize   robotSize;
        int         batteryLife;
        int         probFailure;
        /*
        Room        destination;
        Task        currentTask;
        vector<Task>  completedTasks;
        */

    public:
        Robot(RobotType type, RobotSize size);
        Robot(const Robot& other);
        ~Robot();
        int robotID;

        bool getActive();
        bool getBrokenStatus();
        void setBrokenStatus(bool);
        RobotType getRobotType() const;
        RobotSize getRobotSize() const;
        int getBattery();
        void charge();
        std::string getRobotID() const;
        
        /*
        Room getDestination();
        void setDestination(Room);
        Task getTask();
        void setTask(Task);
        vector<Task> getCompletedTasks();
        */

        void printRobot();
};

#endif // LIBCLEAN_ROBOT_HPP