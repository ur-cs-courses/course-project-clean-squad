cmake_minimum_required(VERSION 3.16)
project(libclean)

include(dependencies.cmake)

add_library(libclean
    src/Robot.cpp
    src/Room.cpp
    src/Task.cpp
)

target_include_directories(libclean
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)

target_link_libraries(libclean
  fmt::fmt
)

add_subdirectory(app)
