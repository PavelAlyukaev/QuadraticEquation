cmake_minimum_required(VERSION 3.24)
project(SolverLib)

set(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE
        include/Solver.h
        src/Solver.cpp
)
MESSAGE(${PROJECT_NAME})

add_library(${PROJECT_NAME} STATIC ${SOURCE})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/SolverLib/include)

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
            /W4
    )
else ()
    target_compile_options(${PROJECT_NAME} PRIVATE
            -Wall -Wextra -pedantic -Werror
    )
endif()