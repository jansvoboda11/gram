cmake_minimum_required(VERSION 3.6.0)

project(gram)

option(build_gram_tests "Build Gram tests." OFF)

set(CMAKE_CXX_FLAGS "-std=gnu++14")

add_subdirectory(src)

if (build_gram_tests)
    add_subdirectory(test)
endif ()
