cmake_minimum_required(VERSION 3.23.0)
project(Commands)

set (CMAKE_CXX_STANDARD 17)

set(SOURCES
    Commands.cpp
    Commands.h  
    )

add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE CRC)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
