set(GTEST_ROOT ../lib/googletest/googletest)

include_directories(GTEST_ROOT GTEST_ROOT/include)
include_directories(../../include)
include_directories(../fake/include)

add_executable(gram_unit_tests
        evolution/fitness_calculator/parabola_fitness_calculator_test.cpp
        evolution/operator/crossover_test.cpp
        evolution/operator/mutation_test.cpp
        evolution/evolution_builder_test.cpp
        evolution/evolution_test.cpp
        evolution/selector/individual_selector_test.cpp
        evolution/selector/tournament_selector_test.cpp
        fake/util/bool_generator_test.cpp
        fake/util/number_generator_test.cpp
        grammar/rule_parser/bnf_rule_parser_test.cpp
        grammar/symbol/non_terminal_symbol_test.cpp
        grammar/symbol/option_test.cpp
        grammar/symbol/terminal_symbol_test.cpp
        grammar/grammar_test.cpp
        individual/genotype_test.cpp
        individual/individual_test.cpp
        individual/mapper_test.cpp
        individual/phenotype_test.cpp
        language/evaluator_test.cpp
        population/initializer_test.cpp
        population/population_test.cpp
        )

target_link_libraries(gram_unit_tests gtest gtest_main)
target_link_libraries(gram_unit_tests gram_test_fake)
target_link_libraries(gram_unit_tests gram)
