cmake_minimum_required(VERSION 2.8.12)

project(gram)

option(build_gram_tests "Build Gram tests." OFF)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)

if (build_gram_tests)
    add_subdirectory(test)
endif ()
