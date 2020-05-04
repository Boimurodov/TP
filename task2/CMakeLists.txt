cmake_minimum_required (VERSION 3.0)

project (TP_task2)

set (CMAKE_CXX_STANDARD_REQUIRED on)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

find_package (GTest)
find_package (Threads)

include_directories (${GTEST_INCLUDE_DIRS})
include_directories (${PROJECT_SOURCE_DIR}/A)

add_subdirectory (B ${PROJECT_SOURCE_DIR}/lib)

execute_process (COMMAND python preparing.py WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/A)

add_executable (C ${PROJECT_SOURCE_DIR}/C/main.cpp)
target_link_libraries (C Blib)
target_include_directories (C PUBLIC "${CMAKE_CURRENT_LIST_DIR}")

add_executable (CTest ${PROJECT_SOURCE_DIR}/C/main_test.cpp)
target_link_libraries (CTest Blib)
target_include_directories (CTest PUBLIC "${CMAKE_CURRENT_LIST_DIR}")

target_link_libraries (CTest ${GTEST_LIBRARIES} Threads::Threads)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
