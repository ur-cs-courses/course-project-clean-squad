#define CATCH_CONFIG_MAIN
#include "include/libclean/catch.hpp"
#include "include/libclean/Robot.hpp"



TEST_CASE( "Robot is working") {
    Robot newRobot(RobotType::mopper, RobotSize::small);
    
    SECTION( "Default values" ) {
        REQUIRE( newRobot.getRobotType() == RobotType::mopper );
        REQUIRE( newRobot.getRobotSize() == RobotType::small );
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

