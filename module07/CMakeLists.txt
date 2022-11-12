cmake_minimum_required(VERSION 3.14)
project(study_asio)

set(CMAKE_CXX_STANDARD 17)

add_executable(lottery-server lottery-server.cpp)
add_executable(lottery-client lottery-client.cpp)

target_link_libraries(lottery-server pthread boost_system)
target_link_libraries(lottery-client pthread boost_system)
