#include <libclean/Robot.hpp>
#include <libclean/Room.hpp>
#include <libclean/Task.hpp>
#include <iostream>

auto main() noexcept -> int {
    Task myTask;
    myTask.setNumRobots(20); 
    int numberOfRobots = myTask.getNumRobots();
    std::cout << "Number of robots: " << numberOfRobots << std::endl;

    return 0;
}
