include_directories(../lib/catch/src/catch/single_include)
include_directories(../lib/fakeit/src/fakeit/single_header/catch)
include_directories(../../include)

add_executable(gram-unit-tests
        evaluation/driver/multi_thread_driver_test.cpp
        evaluation/driver/single_thread_driver_test.cpp
        individual/comparer/high_fitness_comparer_test.cpp
        individual/comparer/low_fitness_comparer_test.cpp
        individual/crossover/one_point_crossover_test.cpp
        individual/mutation/bernoulli_step_generator_test.cpp
        individual/mutation/fast_codon_mutation_test.cpp
        individual/mutation/naive_codon_mutation_test.cpp
        individual/individual_test.cpp
        language/grammar/context_free_grammar_test.cpp
        language/mapper/context_free_mapper_test.cpp
        language/parser/bnf_rule_parser_test.cpp
        language/symbol/non_terminal_test.cpp
        language/symbol/option_test.cpp
        language/symbol/rule_test.cpp
        language/symbol/terminal_test.cpp
        population/initializer/random_initializer_test.cpp
        population/reproducer/passionate_reproducer_test.cpp
        population/selector/tournament_selector_test.cpp
        population/individuals_test.cpp
        population/population_test.cpp
        util/helper_test.cpp
        evolution_test.cpp
        test.cpp
        )

add_dependencies(gram-unit-tests catch fakeit)

target_link_libraries(gram-unit-tests gram)
