include_directories(../include)

set(SOURCE_FILES
        evolution/fitness_calculator/ParabolaFitnessCalculator.cpp
        evolution/operator/Crossover.cpp
        evolution/operator/Mutation.cpp
        evolution/selector/TournamentSelector.cpp
        evolution/Evolution.cpp
        evolution/EvolutionBuilder.cpp
        grammar/rule_parser/BnfRuleParser.cpp
        grammar/symbol/NonTerminal.cpp
        grammar/symbol/Option.cpp
        grammar/symbol/Terminal.cpp
        grammar/Grammar.cpp
        individual/Individual.cpp
        individual/Mapper.cpp
        individual/Phenotype.cpp
        population/generator/Generator.cpp
        population/initializer/RandomInitializer.cpp
        population/processor/Processor.cpp
        population/Population.cpp
        util/bool_generator/TwisterBoolGenerator.cpp
        util/number_generator/TwisterNumberGenerator.cpp
        )

add_library(gram STATIC ${SOURCE_FILES})
