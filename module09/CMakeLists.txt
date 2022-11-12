cmake_minimum_required(VERSION 3.14)
project(exercise01)

include_directories(/usr/local/include/bsoncxx/v_noabi /usr/local/include/mongocxx/v_noabi)
set(CMAKE_CXX_STANDARD 14)
link_directories(/usr/local/lib)

add_executable(exercise01 exercise01.cpp)
add_executable(exercise02 exercise02.cpp)
add_executable(exercise03 exercise03.cpp)
add_executable(exercise04 exercise04.cpp)
add_executable(exercise05 exercise05.cpp)
add_executable(exercise06 exercise06.cpp)

target_link_libraries(exercise01 mongocxx bsoncxx)
target_link_libraries(exercise02 mongocxx bsoncxx)
target_link_libraries(exercise03 mongocxx bsoncxx)
target_link_libraries(exercise04 mongocxx bsoncxx)
target_link_libraries(exercise05 mongocxx bsoncxx)
target_link_libraries(exercise06 mongocxx bsoncxx)

