#define CATCH_CONFIG_MAIN
#include "include/libclean/catch.hpp"
#include "include/libclean/Robot.hpp"



TEST_CASE( "Robot is working") {
    Robot newRobot(RobotType::mopper, RobotSize::small);
    
    REQUIRE( newRobot.getRobotType() == RobotType::mopper );
    REQUIRE( newRobot.getRobotSize() == RobotType::small );

     SECTION( "Getters and setters" ) {
        newRobot.

        REQUIRE( newRobot.getRobotType() == RobotType::mopper );
        REQUIRE( newRobot.getRobotSize() == RobotType::small );
    }
}

