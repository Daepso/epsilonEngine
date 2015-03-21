project(epsilonEngine)
cmake_minimum_required(VERSION 2.8)

include_directories(src/)

set(SOURCES
	src/shader.cpp
	src/shaderprogram.cpp)

add_library(${PROJECT_NAME} ${SOURCES})

set(EPSILON_ENGINE_LIBRARIES ${PROJECT_NAME} PARENT_SCOPE)
set(EPSILON_ENGINE_INCLUDE ${CMAKE_SOURCE_DIR} PARENT_SCOPE)
