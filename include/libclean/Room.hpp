#ifndef LIBCLEAN_ROOM_HPP
#define LIBCLEAN_ROOM_HPP

#include <string>
#include <vector>

using namespace std;

enum class RoomSize {small, medium, large};

class Room {
private:
    int mopTime;
    int vacuumTime;
    int scrubTime;
    int mopping;
    int vacuum;
    int scrubber;
    RoomSize roomSize;
    int area;

public:
    Room();

    void setRoomSize(RoomSize newSize);
    RoomSize getRoomSize() const;
    int getMopTime() const;
    int getVacuumTime() const;
    int getScrubTime() const;
    int getNumMopping() const;
    int getNumVacuum() const;
    int getNumScrubber() const;

};

#endif

