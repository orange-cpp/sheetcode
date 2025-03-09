cmake_minimum_required(VERSION 3.26)
enable_testing()

project(solutions)

add_subdirectory(extlibs/googletest)

include(GoogleTest)
add_executable(solutions source/MergeIntervals.cpp)

set_target_properties(solutions PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/out/${CMAKE_BUILD_TYPE}"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/out/${CMAKE_BUILD_TYPE}"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/out/${CMAKE_BUILD_TYPE}"
        UNITY_BUILD ON
        UNITY_BUILD_BATCH_SIZE 20
        CXX_STANDARD 23
        CXX_STANDARD_REQUIRED ON)


target_link_libraries(solutions PRIVATE gtest gtest_main)

gtest_discover_tests(solutions)