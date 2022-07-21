############################################################
cmake_minimum_required(VERSION 3.10.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
############################################################

set(PROJECT_NAME "sheDB")
set(3RD_DIR "./third-party")
set(FRAMEWORK_DIR "./framework")
############################################################
project(${PROJECT_NAME})
############################################################
include_directories(${3RD_DIR}/)

############################################################
include_directories("src")
include_directories("framework")
file(GLOB_RECURSE SOURCE "${CMAKE_SOURCE_DIR}/src/*")
file(GLOB_RECURSE FRAMEWORK "${FRAMEWORK_DIR}/*")

add_executable(${PROJECT_NAME}
        ${SOURCE}
        ${FRAMEWORK})

############################################################
target_link_libraries(${PROJECT_NAME} pthread)