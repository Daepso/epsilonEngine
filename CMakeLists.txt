project(epsilonEngine)
cmake_minimum_required(VERSION 2.8)

include_directories(src/)

set(SOURCES
	src/shader.cpp)

add_library(${PROJECT_NAME} ${SOURCES})
