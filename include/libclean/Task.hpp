#ifndef TASK_HPP
#define TASK_HPP

#include <vector>

class Task {
private:
    int numRobots;
    // std::vector<Robot> workingRobots; -> not included the robot class yet
    //Also needs Tasklocation from Room
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

    void printTask();
};
#endif

