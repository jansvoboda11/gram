include_directories(../include)

set(SOURCE_FILES
        evolution/operator/Crossover.cpp
        evolution/operator/Mutation.cpp
        evolution/Evolution.cpp
        evolution/EvolutionBuilder.cpp
        evolution/FitnessCalculator.cpp
        language/grammar/rule_parser/BnfRuleParser.cpp
        language/grammar/symbol/NonTerminal.cpp
        language/grammar/symbol/Terminal.cpp
        language/grammar/Grammar.cpp
        language/grammar/Rule.cpp
        population/individual/Individual.cpp
        population/individual/Mapper.cpp
        population/individual/Phenotype.cpp
        population/Initializer.cpp
        population/Population.cpp
        )

add_library(gram STATIC ${SOURCE_FILES})
