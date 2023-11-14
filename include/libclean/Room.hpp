#ifndef LIBCLEAN_ROOM_HPP
#define LIBCLEAN_ROOM_HPP

#include <string>
#include <vector>
#include "Robot.hpp"

using namespace std;

enum class RoomSize {small, medium, large};

class Room {

static int nextID;
private:
    int mopTime;
    int vacuumTime;
    int scrubTime;
    int mopping;
    int vacuum;
    int scrubber;
    RoomSize roomSize;
    int area;
    vector<Robot> currentRobots;

public:
    int id; //unique ID for each room
    Room();
    Room(int mop, int vacuum, int scrub, RoomSize room);
    std::string getIDAsString() const; // Method to get the ID as a string

    void setRoomSize(RoomSize newSize);
    RoomSize getRoomSize() const;
    int getMopTime() const;
    int getVacuumTime() const;
    int getScrubTime() const;
    int getNumMopping() const;
    int getNumVacuum() const;
    int getNumScrubber() const;

    void printRoom();
    void printCurrentRobots();
};

#endif

