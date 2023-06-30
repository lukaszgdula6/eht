cmake_minimum_required(VERSION 3.5)

project(eht LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SRC DevicesSocket.cpp MessageStatistics.cpp)
set (SRC_GT GT/gmock-gtest-all.cc GT/gmock_main.cc GT/MessageStatisticsTestSuite.cpp)

add_executable(eht main.cpp ${SRC})
add_executable(eht_GT ${SRC} ${SRC_GT})

target_include_directories(eht_GT PRIVATE . GT GT/Mocks)
target_link_libraries(eht_GT pthread)
