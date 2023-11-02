#include "libhello/room.hpp"
#include <fmt/core.h>
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

    Room() : mopTime(0), vacuumTime(0), scrubTime(0), mopping(0), vacuum(0), scrubber(0), roomSize("small"), area(0) {}

public:

    void setRoomSize(const string& newSize) {
        roomSize = newSize;
    }

    string getRoomSize() const {
        return roomSize;
    }

    int getMopTime() const {
        return mopTime;
    }

    int getVacuumTime() const {
        return vacuumTime;
    }

    int getScrubTime() const {
        return scrubTime;
    }

    int getNumMopping() const {
        return mopping;
    }

    int getNumVacuum() const {
        return vacuum;
    }

    int getNumScrubber() const {
        return scrubber;
    }
};

#endif