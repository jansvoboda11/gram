option(build_gram_tests "Build Gram tests." OFF)

cmake_minimum_required(VERSION 3.6.0)

project(gram)

add_subdirectory(src)

if (build_gram_tests)
    add_subdirectory(test)
endif ()
