cmake_minimum_required(VERSION 3.9)
project(openCV)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenCV)

include_directories(${OpenCV_INCLUDE_DIRS})
set(CMAKE_CXX_STANDARD 17)

add_executable(openCV main.cpp)

target_link_libraries(openCV ${OpenCV_LIBS})
