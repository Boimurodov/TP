cmake_minimum_required(VERSION 3.10.2)
project(task2)

add_custom_command(
        OUTPUT ${PROJECT_SOURCE_DIR}/A/index.h
        COMMAND python ${PROJECT_SOURCE_DIR}/A/preparing.py "${PROJECT_SOURCE_DIR}/A/index.h"
        DEPENDS ${PROJECT_SOURCE_DIR}/A/preparing.py
)

add_custom_target(RunGenerator DEPENDS ${PROJECT_SOURCE_DIR}/A/index.h)

set(CMAKE_CXX_STANDARD 17)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif ()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif ()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif ()

add_subdirectory(B ../lib/SegmentTree)

add_executable(CTest C/main_test.cpp)
add_executable(C C/main.cpp)
add_dependencies(C RunGenerator)
add_dependencies(CTest RunGenerator)

target_include_directories(C PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(CTest gtest_main SegmentTree)
target_link_libraries(C SegmentTree)
target_include_directories(CTest PUBLIC ${PROJECT_SOURCE_DIR})

set_target_properties(C CTest
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin"
        )


