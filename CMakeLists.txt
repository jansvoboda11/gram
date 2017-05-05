cmake_minimum_required(VERSION 2.8.12)

project(gram)

option(GRAM_BUILD_TESTS "Build Gram tests." OFF)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)

if (GRAM_BUILD_TESTS)
    add_subdirectory(test)
endif ()
