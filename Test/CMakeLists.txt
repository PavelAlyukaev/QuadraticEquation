cmake_minimum_required(VERSION 3.24)
project(TestSolver)

set(CMAKE_CXX_STANDARD 20)

SET(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE
        Src/TestMain.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE})
set_target_properties( ${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR} )

target_include_directories(${PROJECT_NAME}
        PRIVATE ${CMAKE_SOURCE_DIR}/SolverLib/include
        PRIVATE ${CMAKE_SOURCE_DIR}/googletest/include
)

target_link_libraries(${PROJECT_NAME}

        PRIVATE SolverLib
        PRIVATE gtest
        PRIVATE gtest_main
)

if (MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    target_compile_options(${PROJECT_NAME} PRIVATE
            /W4
    )
else ()
    target_compile_options(${PROJECT_NAME} PRIVATE
            -Wall -Wextra -pedantic -Werror
    )
endif()