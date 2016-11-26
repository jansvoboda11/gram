set(GTEST_ROOT ../lib/googletest/googletest)

include_directories(GTEST_ROOT GTEST_ROOT/include)
include_directories(../../src)
include_directories(../fake)

add_executable(gram_unit_tests
        evolution/operator/crossover_test.cpp
        evolution/operator/mutation_test.cpp
        evolution/evolution_builder_test.cpp
        evolution/evolution_test.cpp
        evolution/fitness_calculator_test.cpp
        evolution/individual_selector_test.cpp
        fake/util/number_generator_test.cpp
        language/grammar/rule_parser/bnf_rule_parser_test.cpp
        language/grammar/symbol/non_terminal_symbol_test.cpp
        language/grammar/symbol/terminal_symbol_test.cpp
        language/grammar/grammar_test.cpp
        language/grammar/rule_test.cpp
        language/evaluator_test.cpp
        population/individual/genotype_test.cpp
        population/individual/individual_test.cpp
        population/individual/mapper_test.cpp
        population/individual/phenotype_test.cpp
        population/initializer_test.cpp
        population/population_test.cpp
        )

target_link_libraries(gram_unit_tests gtest gtest_main)
target_link_libraries(gram_unit_tests gram_test_fake)
target_link_libraries(gram_unit_tests gram)
