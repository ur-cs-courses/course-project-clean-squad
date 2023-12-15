cmake_minimum_required(VERSION 3.16)
project(libclean)

include(dependencies.cmake)
find_package(mongocxx REQUIRED)
find_package(bsoncxx REQUIRED)

add_library(libclean
  src/Robot.cpp
  src/room.cpp
  src/Task.cpp
  src/Simulation.cpp
  src/mongoDB.cpp
)

target_include_directories(libclean
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:/opt/homebrew/include/mongocxx/v_noabi>
    $<BUILD_INTERFACE:/opt/homebrew/include/bsoncxx/v_noabi>
)

target_link_libraries(libclean
  fmt::fmt
  mongo::mongocxx_shared
)

add_subdirectory(app)
add_subdirectory(tests)
