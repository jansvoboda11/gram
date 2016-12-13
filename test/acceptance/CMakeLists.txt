include_directories(../lib/googletest/googlemock/include)
include_directories(../../include)
include_directories(../mock)

add_executable(gram_acceptance_tests
        evolution.cpp
        )

target_link_libraries(gram_acceptance_tests gtest gmock_main)
target_link_libraries(gram_acceptance_tests gram)
