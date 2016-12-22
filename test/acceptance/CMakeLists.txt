include_directories(../lib/googletest/googletest/include)
include_directories(../lib/fakeit/src/fakeit/single_header)
include_directories(../../include)

add_executable(gram_acceptance_tests
        evolution_test.cpp
        )

add_dependencies(gram_unit_tests fakeit)

target_link_libraries(gram_acceptance_tests gram gtest gtest_main)
