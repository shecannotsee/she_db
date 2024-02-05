
########################################################################################################################
# Import lib                                                                                                           #
########################################################################################################################

# include
include_directories(${CMAKE_SOURCE_DIR}/third_party/she_test/include)
include_directories(${CMAKE_SOURCE_DIR}/third_party/she_log/include)


# lib
link_directories(${CMAKE_SOURCE_DIR}/third_party/she_log/lib)

# Internal project
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/test)
include_directories(${CMAKE_SOURCE_DIR}/exec)


