include_directories(../lib/googletest/googlemock/include)
include_directories(../lib/fakeit/src/fakeit/single_header)
include_directories(../../include)

add_executable(gram_unit_tests
        individual/fitness/parabola_fitness_calculator_test.cpp
        individual/operator/inverse_one_point_crossover_test.cpp
        individual/operator/mutation_test.cpp
        individual/operator/one_point_crossover_test.cpp
        individual/individual_test.cpp
        individual/phenotype_test.cpp
        language/parser/bnf_rule_parser_test.cpp
        language/symbol/non_terminal_test.cpp
        language/symbol/option_test.cpp
        language/symbol/terminal_test.cpp
        language/context_free_grammar_test.cpp
        population/initializer/random_initializer_test.cpp
        population/reproducer/reproducer_test.cpp
        population/selector/tournament_selector_test.cpp
        population/individuals_test.cpp
        population/population_test.cpp
        util/helper_test.cpp
        evolution_builder_test.cpp
        evolution_test.cpp
        )

add_dependencies(gram_unit_tests fakeit)

target_link_libraries(gram_unit_tests gram gtest gtest_main)
