cmake_minimum_required(VERSION 3.10.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_NAME "sheDB")
set(3RD_DIR "./third-party")
set(FRAMEWORK_DIR "./framework")

aux_source_directory(./src SOURCE_DODE_DIR)
add_executable(${PROJECT_NAME} ${SOURCE})

target_link_libraries(${PROJECT_NAME} pthread)