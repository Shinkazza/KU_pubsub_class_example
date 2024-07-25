cmake_minimum_required(VERSION 3.0.2)
project(pubsub)




find_package(catkin REQUIRED COMPONENTS
 roscpp
 std_msgs
)


catkin_package(
)


include_directories(
 include                   
 ${catkin_INCLUDE_DIRS}
)


add_executable(example src/pubsub.cpp src/main.cpp)
target_link_libraries(example ${catkin_LIBRARIES})
