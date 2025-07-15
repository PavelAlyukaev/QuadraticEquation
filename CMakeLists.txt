cmake_minimum_required(VERSION 3.24)
project(QuadraticEquation)

set(CMAKE_CXX_STANDARD 20)


SET(BIN_DIR "${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}")
add_subdirectory("${CMAKE_SOURCE_DIR}/googletest"
        "googletest")
add_subdirectory("Test")
add_subdirectory("SolverLib")


include(CPack)

enable_testing()
add_test(Test1 ${CMAKE_SOURCE_DIR})