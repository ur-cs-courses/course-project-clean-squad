#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "libclean/Robot.hpp"
#include "libclean/Room.hpp"

TEST_CASE( "Robot is working") {
    Robot newRobot(RobotType::mopper, RobotSize::small);
    
    SECTION( "Default values" ) {
        REQUIRE( newRobot.getRobotType() == RobotType::mopper );
        REQUIRE( newRobot.getRobotSize() == RobotSize::small );
        REQUIRE( newRobot.getActive() == false);
        REQUIRE( newRobot.getBrokenStatus() == false);
        REQUIRE( newRobot.getBattery() == 50);
    }

    SECTION( "Break robot" ) {
        newRobot.setBrokenStatus(true);

        REQUIRE( newRobot.getBrokenStatus() == true);
    }

    SECTION( "Charge robot" ) {
        newRobot.charge();

        REQUIRE( newRobot.getBattery() == 50);
    }

/**
    SECTION( "Probability of Failure" ) {
        REQUIRE( newRobot.failGrade() < 6);
    }  
 **/          
}


TEST_CASE( "Room is working") {

    Room newRoom(RoomSize::large);
    
    SECTION( "Default values" ) {
        REQUIRE(newRoom.getRoomSize() == RoomSize::large);
        REQUIRE(newRoom.getMopTime() == 200);
        REQUIRE(newRoom.getVacuumTime() == 200);
        REQUIRE(newRoom.getScrubTime() == 200);
        REQUIRE(newRoom.getNumMopping() == 0);
        REQUIRE(newRoom.getNumVacuum() == 0);
        REQUIRE(newRoom.getNumScrubber() == 0);
    }

    SECTION( "Check clean" ) {
        newRoom.setClean(cleanStatus::dirty);
        REQUIRE(newRoom.getClean() == cleanStatus::dirty);

        newRoom.setClean(cleanStatus::clean);
        REQUIRE(newRoom.getClean() == cleanStatus::clean);

        newRoom.setClean(cleanStatus::cleaning);
        REQUIRE(newRoom.getClean() == cleanStatus::cleaning);

        newRoom.setClean(cleanStatus::doNotClean);
        REQUIRE(newRoom.getClean() == cleanStatus::doNotClean);
    }
}