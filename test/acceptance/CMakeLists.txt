include_directories(../lib/catch/src/catch/single_include)
include_directories(../lib/fakeit/src/fakeit/single_header/catch)
include_directories(../../include)

add_executable(gram-acceptance-tests
        StringDiffEvaluator.cpp
        StringDiffEvaluator.h
        evolution_test.cpp
        test.cpp
        )

add_dependencies(gram-acceptance-tests catch fakeit)

target_link_libraries(gram-acceptance-tests gram)
