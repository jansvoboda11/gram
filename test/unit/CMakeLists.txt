add_executable(utest
        evaluation/driver/multi_thread_driver_test.cpp
        evaluation/driver/single_thread_driver_test.cpp
        evaluation/evaluator_cache_text.cpp
        individual/individual_test.cpp
        language/grammar/context_free_grammar_test.cpp
        language/mapper/context_free_mapper_test.cpp
        language/parser/bnf_rule_parser_test.cpp
        language/symbol/non_terminal_test.cpp
        language/symbol/option_test.cpp
        language/symbol/rule_test.cpp
        language/symbol/terminal_test.cpp
        operator/crossover/one_point_crossover_test.cpp
        operator/mutation/bernoulli_step_generator_test.cpp
        operator/mutation/codon_mutation_test.cpp
        operator/selector/comparer/high_fitness_comparer_test.cpp
        operator/selector/comparer/low_fitness_comparer_test.cpp
        operator/selector/tournament_selector_test.cpp
        population/initializer/random_initializer_test.cpp
        population/reproducer/passionate_reproducer_test.cpp
        population/individuals_test.cpp
        population/population_test.cpp
        util/helper_test.cpp
        evolution_test.cpp
        test.cpp
        )

target_include_directories(utest PRIVATE
        ${gram_SOURCE_DIR}/include
        ${catch_INCLUDE_DIR}
        ${fakeit_INCLUDE_DIR}
        )

target_link_libraries(utest gram)
