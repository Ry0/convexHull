cmake_minimum_required(VERSION 2.8)
ADD_DEFINITIONS(
  -Wall
  -g
  -O2
  -std=c++11
)

project( Labeling )

find_package(OpenCV REQUIRED)

add_executable( Labeling labeling.cpp)
target_link_libraries( Labeling ${OpenCV_LIBRARIES})
