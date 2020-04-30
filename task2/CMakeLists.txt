cmake_minimum_required(VERSION 3.10.2)
project(CmakeBuildProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

execute_process(COMMAND python3 preparing.py WORKING_DIRECTORY A)

include_directories(B)
add_subdirectory(B)

add_executable(CmakeBuildProject C/main.cpp)
add_dependencies(CmakeBuildProject Header)

target_include_directories(CmakeBuildProject PRIVATE ${CMAKE_BINARY_DIR})
target_link_libraries(CmakeBuildProject Lib)

