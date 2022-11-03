cmake_minimum_required(VERSION 3.23)
project(module06)

set(CMAKE_CXX_STANDARD 17)

add_executable(exercise01 exercise01.cpp country.cpp country.h city.cpp city.h world-util.cpp world-util.h)
add_executable(exercise02 exercise02.cpp)
add_executable(exercise03 exercise03.cpp)
add_executable(study-maps study-maps.cpp)
add_executable(study-stl-algorithms study-stl-algorithms.cpp)
add_executable(study-how-to-iterate study-how-to-iterate.cpp)
