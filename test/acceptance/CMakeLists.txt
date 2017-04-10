include_directories(../lib/catch/src/catch/single_include)
include_directories(../lib/fakeit/src/fakeit/single_header/catch)
include_directories(../../include)

add_executable(gram_acceptance_tests
        evolution_test.cpp
        test.cpp
        )

add_dependencies(gram_acceptance_tests catch fakeit)

target_link_libraries(gram_acceptance_tests gram)
