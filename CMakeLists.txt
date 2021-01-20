cmake_minimum_required(VERSION 3.0)
project(SimpleTimer)

add_subdirectory(Timer)

SET(CMAKE_CXX_FLAGS -pthread)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} Timer)