cmake_minimum_required(VERSION 3.8)
project(untitled2)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c setPin.c goForward.c setPin.h goBackward.c turnRight.c turnLeft.c savePin.c)
add_executable(untitled2 ${SOURCE_FILES})