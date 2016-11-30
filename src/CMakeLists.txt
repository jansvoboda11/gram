include_directories(../include)

set(SOURCE_FILES
        evolution/operator/Crossover.cpp
        evolution/operator/Mutation.cpp
        evolution/Evolution.cpp
        evolution/EvolutionBuilder.cpp
        evolution/FitnessCalculator.cpp
        grammar/rule_parser/BnfRuleParser.cpp
        grammar/symbol/NonTerminal.cpp
        grammar/symbol/Terminal.cpp
        grammar/Grammar.cpp
        grammar/Rule.cpp
        individual/Individual.cpp
        individual/Mapper.cpp
        individual/Phenotype.cpp
        population/Initializer.cpp
        population/Population.cpp
        )

add_library(gram STATIC ${SOURCE_FILES})
