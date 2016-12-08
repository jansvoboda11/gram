include_directories(../include)

set(SOURCE_FILES
        evolution/operator/Crossover.cpp
        evolution/operator/Mutation.cpp
        evolution/selector/TournamentSelector.cpp
        evolution/Evolution.cpp
        evolution/EvolutionBuilder.cpp
        evolution/FitnessCalculator.cpp
        grammar/rule_parser/BnfRuleParser.cpp
        grammar/symbol/NonTerminal.cpp
        grammar/symbol/Option.cpp
        grammar/symbol/Terminal.cpp
        grammar/Grammar.cpp
        individual/Individual.cpp
        individual/Mapper.cpp
        individual/Phenotype.cpp
        population/Initializer.cpp
        )

add_library(gram STATIC ${SOURCE_FILES})
