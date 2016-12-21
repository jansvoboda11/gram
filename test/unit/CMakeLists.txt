include_directories(../lib/googletest/googlemock/include)
include_directories(../../include)

add_executable(gram_unit_tests
        evolution/fitness_calculator/parabola_fitness_calculator_test.cpp
        evolution/operator/crossover_test.cpp
        evolution/operator/mutation_test.cpp
        evolution/evolution_builder_test.cpp
        evolution/evolution_test.cpp
        evolution/selector/tournament_selector_test.cpp
        grammar/rule_parser/bnf_rule_parser_test.cpp
        grammar/symbol/non_terminal_test.cpp
        grammar/symbol/option_test.cpp
        grammar/symbol/terminal_test.cpp
        grammar/grammar_test.cpp
        individual/genotype_test.cpp
        individual/individual_test.cpp
        individual/mapper_test.cpp
        individual/phenotype_test.cpp
        population/generator/generator_test.cpp
        population/initializer/random_initializer_test.cpp
        population/processor/processor_test.cpp
        population/population_test.cpp
        )

target_link_libraries(gram_unit_tests gtest gmock_main)
target_link_libraries(gram_unit_tests gram)
