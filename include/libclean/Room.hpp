#ifndef LIBCLEAN_ROOM_HPP
#define LIBCLEAN_ROOM_HPP

#include <string>
#include <vector>
#include "Robot.hpp"

using namespace std;

enum class RoomSize {small, medium, large, home};
enum class cleanStatus {clean, dirty, doNotClean, cleaning};

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
    cleanStatus cleanLevel;

public:
    int id; //unique ID for each room
    Room();
    Room(RoomSize room);

    int getID() const; 
    void setRoomSize(RoomSize newSize);
    RoomSize getRoomSize() const;
    int getMopTime() const;
    int getVacuumTime() const;
    int getScrubTime() const;
    int getNumMopping() const;
    int getNumVacuum() const;
    int getNumScrubber() const;
    cleanStatus getClean() const;
    void setClean(cleanStatus level);
    string getIDAsString() const;

    void printRoom();
    void printCurrentRobots();
};

#endif