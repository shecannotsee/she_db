############################################################
cmake_minimum_required(VERSION 3.10.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
############################################################
set(PROJECT_NAME "sheDB")
set(3RD_DIR "third_party")
set(FRAMEWORK_DIR "./framework")
############################################################
project(${PROJECT_NAME})
############################################################
include_directories(${3RD_DIR})
############################################################
file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/src/*")
add_executable(${PROJECT_NAME} ${SRC})
############################################################
target_link_libraries(${PROJECT_NAME} pthread)