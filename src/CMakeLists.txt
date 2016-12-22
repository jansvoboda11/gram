include_directories(../include)

set(SOURCE_FILES
        individual/fitness/ParabolaFitnessCalculator.cpp
        individual/operator/Crossover.cpp
        individual/operator/Mutation.cpp
        population/selector/TournamentSelector.cpp
        Evolution.cpp
        EvolutionBuilder.cpp
        language/parser/BnfRuleParser.cpp
        language/symbol/NonTerminal.cpp
        language/symbol/Option.cpp
        language/symbol/Terminal.cpp
        language/Grammar.cpp
        individual/Individual.cpp
        individual/Mapper.cpp
        individual/Phenotype.cpp
        language/Language.cpp
        population/generator/Generator.cpp
        population/initializer/RandomInitializer.cpp
        individual/processor/Processor.cpp
        population/Population.cpp
        util/bool_generator/TwisterBoolGenerator.cpp
        util/number_generator/TwisterNumberGenerator.cpp
        )

add_library(gram STATIC ${SOURCE_FILES})
