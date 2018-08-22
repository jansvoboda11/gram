include_directories(../lib/catch/src/catch/single_include/catch2)
include_directories(../lib/fakeit/src/fakeit/single_header/catch)
include_directories(../../include)

add_executable(atest
        StringDiffEvaluator.cpp
        StringDiffEvaluator.h
        evolution_test.cpp
        test.cpp
        )

add_dependencies(atest catch fakeit)

target_link_libraries(atest gram)
