cmake_minimum_required(VERSION 3.23.0)
project(OptionsParser)

set (CMAKE_CXX_STANDARD 17)

set(SOURCES
    BoolOption.h 
    BoolOption.cpp 
    StringOption.h 
    StringOption.cpp
    OptionBase.h 
    OptionBase.cpp 
    OptionParser.h
    OptionParser.cpp
    )

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
