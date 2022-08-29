cmake_minimum_required(VERSION 3.13)

enable_language(CXX)
project(RPI4)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

file(GLOB SRCS */*.cpp)
add_library(RPI4 ${SRCS})
target_include_directories(RPI4 PUBLIC ./)