cmake_minimum_required(VERSION 3.23.0)

project(Parser)

set (CMAKE_CXX_STANDARD 17)

add_subdirectory(src)

set(SOURCES
    ./src/main.cpp
    )

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} Commands Application CRC OptionsParser)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
