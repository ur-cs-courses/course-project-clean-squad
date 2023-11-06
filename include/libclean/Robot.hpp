//Robot Header File

#include <string>
#include <vector>

using namespace std;

enum class RobotType {mopper, sweeper, scrubber};
enum class RobotSize {small, medium, large};

class Robot {
    private:
        bool        isActive;
        bool        isBroken;
        RobotType   robotType;
        RobotSize   robotSize;
        int         batteryLife;
        int         probFailure;
        /*
        Room      destination;
        Task      currentTask;
        vector<Task>  completedTasks;
        */

    public:
        Robot(RobotType type, RobotSize size);
        Robot(const Robot& other);
        ~Robot();

        bool getActive();
        bool getBrokenStatus();
        void setBrokenStatus(bool);
        RobotType getRobotType();
        RobotSize getRobotSize();
        int getBattery();
        void charge();
        /*
        Room getDestination();
        void setDestination(Room);
        Task getTask();
        void setTask();
        vector<Task> getCompletedTasks();
        */
};