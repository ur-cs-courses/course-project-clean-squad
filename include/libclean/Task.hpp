#ifndef TASK_HPP
#define TASK_HPP

#include <vector>
#include "Robot.hpp"
#include "Room.hpp"

class Task {
    
static int nextID;

private:
    int numRobots;
    int mopTime;
    int vacuumTime;
    int scrubTime;
    bool isCompleted;
    std::vector<Robot> robots;
    std::vector<string> robotIDs;
    Room taskLocation;
    int roomID;
    int id;

public:
    Task();
    Task(std::vector<Robot> robots, Room taskLocation);

    // Getters
    int getNumRobots() const;
    int getMopTime() const;
    int getVacuumTime() const;
    int getScrubTime() const;
    bool getIsCompleted() const;

    // Setters
    void setNumRobots(int numRobots);
    void setMopTime(int mopTime);
    void setVacuumTime(int vacuumTime);
    void setScrubTime(int scrubTime);
    void setIsCompleted(bool isCompleted);
    
    void printTask();
    int getID();
};
#endif

