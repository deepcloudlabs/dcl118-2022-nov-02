cmake_minimum_required(VERSION 3.14)
project(exercise01)

set(CMAKE_CXX_STANDARD 14)

add_executable(exercise01 exercise01.cpp)
add_executable(exercise02 exercise02.cpp)
add_executable(exercise03 exercise03.cpp)
add_executable(exercise04 exercise04.cpp)
add_executable(exercise05 exercise05.cpp)
add_executable(exercise06 exercise06.cpp)
add_executable(exercise07 exercise07.cpp)
add_executable(exercise08 exercise08.cpp)
add_executable(exercise09 exercise09.cpp)
add_executable(exercise10 exercise10.cpp)
add_executable(exercise11 exercise11.cpp)
add_executable(exercise12 exercise12.cpp)
add_executable(exercise13 exercise13.cpp)

include_directories(/usr/include/mysql-cppconn-8/jdbc)

target_link_libraries(exercise01 mysqlcppconn8 mysqlcppconn)
target_link_libraries(exercise02 mysqlcppconn8 mysqlcppconn)
target_link_libraries(exercise03 mysqlcppconn8 mysqlcppconn)
target_link_libraries(exercise04 mysqlcppconn8 mysqlcppconn)
target_link_libraries(exercise05 mysqlcppconn8 mysqlcppconn)
target_link_libraries(exercise06 mysqlcppconn8 mysqlcppconn)
target_link_libraries(exercise07 mysqlcppconn8 mysqlcppconn)
target_link_libraries(exercise08 mysqlcppconn8 mysqlcppconn)
target_link_libraries(exercise09 mysqlcppconn8 mysqlcppconn)
target_link_libraries(exercise10 mysqlcppconn8 mysqlcppconn)
target_link_libraries(exercise11 mysqlcppconn8 mysqlcppconn)
target_link_libraries(exercise12 mysqlcppconn8 mysqlcppconn)
target_link_libraries(exercise13 mysqlcppconn8 mysqlcppconn)