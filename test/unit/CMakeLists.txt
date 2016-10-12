set(GTEST_ROOT ../lib/googletest/googletest)

include_directories(GTEST_ROOT GTEST_ROOT/include)

add_executable(gram_unit_tests
        greeter_test.cpp
        )

target_link_libraries(gram_unit_tests gtest gtest_main)
target_link_libraries(gram_unit_tests gram)
