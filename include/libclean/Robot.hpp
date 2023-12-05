#ifndef LIBCLEAN_ROBOT_HPP
#define LIBCLEAN_ROBOT_HPP

#include <string>
#include <vector>

class Room;

using namespace std;

enum class RobotType {mopper, vacuum, scrubber};
enum class RobotSize {small, medium, large};

class Robot {

    private:
        static int nextRobotID;
        bool        isActive;
        bool        isBroken;
        RobotType   robotType;
        RobotSize   robotSize;
        int         batteryLife;
        int         probFailure;                                                                   // higher number = higher chance of failure (must be < 5)
        Room*       destination;

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
        std::string getRobotID() const;
        int getID();
        void charge();                                                                             // sets battery to 100
        int failGrade();                                                                           // grade of failure from 1-5s
           
        Room getDestination();
        void printRobot();                                                                         // prints ID, size, type, and failure probability

        //A method to convert enum robotType to string
        std::string getRobotTypeString() const {
        switch(robotType) {
            case RobotType::mopper: return "mopper";
            case RobotType::vacuum: return "vacuum";
            case RobotType::scrubber: return "scrubber";
            default: return "unknown";
              }}

        //A method to convert enum roboSize to string
       std::string getRobotSizeString() const {
        switch(robotSize) {
            case RobotSize::small: return "small";
            case RobotSize::medium: return "medium";
            case RobotSize::large: return "large";
            default: return "unknown";
             }}
};

#endif // LIBCLEAN_ROBOT_HPP
