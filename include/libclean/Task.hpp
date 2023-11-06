#ifndef TASK_HPP
#define TASK_HPP

#include <vector>
//class Room; 
//class Robot;  

class Task {
private:
    int numRobots;
    int mopTime;
    int vacuumTime;
    int scrubTime;
    bool isCompleted;

    //others
    //std::vector<Robot*> workingRobots;
    //Room* taskLocation;

public:
    Task(); // constructor

    // Getters
    int getNumRobots() const;
    int getMopTime() const;
    int getVacuumTime() const;
    int getScrubTime() const;
    bool getIsCompleted() const;
    //std::vector<Robot*> getWorkingRobots() const;
    //Room* getTaskLocation() const;
   

    // Setters
    void setNumRobots(int numRobots);
    void setMopTime(int mopTime);
    void setVacuumTime(int vacuumTime);
    void setScrubTime(int scrubTime);
    void setIsCompleted(bool isCompleted);
     //void addWorkingRobot(Robot* robot);
    //void setTaskLocation(Room* location);
};
#endif

