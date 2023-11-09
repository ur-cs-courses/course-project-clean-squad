#ifndef TASK_HPP
#define TASK_HPP

#include <vector>
#include "Robot.hpp"
#include "Room.hpp"

class Task {
private:
    int numRobots;
    std::vector<Robot> workingRobots;
    int mopTime;
    int vacuumTime;
    int scrubTime;
    bool isCompleted;

public:
    Task();

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
};
#endif

