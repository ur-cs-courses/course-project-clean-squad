#ifndef LIBROOM_ROOM_HPP
#define LIBROOM_ROOM_HPP

#include <string>
#include <vector>

using namespace std;

class Room {
private:
    int mopTime;
    int vacuumTime;
    int scrubTime;
    int mopping;
    int vacuum;
    int scrubber;
    string roomSize;
    int area;

public:
    Room();

    void setRoomSize(const string& newSize);

    string getRoomSize() const;
    int getMopTime() const;
    int getVacuumTime() const;
    int getScrubTime() const;
    int getNumMopping() const;
    int getNumVacuum() const;
    int getNumScrubber() const;

};

#endif

