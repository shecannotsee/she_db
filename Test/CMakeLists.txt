############################################################
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
############################################################
set(PROJECT_NAME "sheDB_test")
############################################################
project(${PROJECT_NAME})
############################################################
# include
include_directories()
# lib
link_directories()
############################################################
# aux_source_directory(. SOURCE)
file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/src/*")
add_executable(${PROJECT_NAME} ${SRC})
############################################################
# 链接库
target_link_libraries(${PROJECT_NAME} pthread)
