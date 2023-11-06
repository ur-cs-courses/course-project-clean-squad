#include <libclean/Robot.hpp>
#include <libclean/Room.hpp>
#include <libclean/Task.hpp>
#include <iostream>

auto main() noexcept -> int {
    Task task;

    task.setMopTime(5);
    task.setVacuumTime(10);
    task.setScrubTime(7);
    task.setIsCompleted(false);

    // Tests
    assert(task.getMopTime() == 5);
    assert(task.getVacuumTime() == 10);
    assert(task.getScrubTime() == 7);
    assert(task.getIsCompleted() == false);

    // Output the results
    std::cout << "All tests passed!" << std::endl;


    return 0;
}
