include_directories(../include)

set(SOURCE_FILES
        individual/fitness/ParabolaFitnessCalculator.cpp
        individual/operator/Crossover.cpp
        individual/operator/Mutation.cpp
        individual/processor/Processor.cpp
        individual/Individual.cpp
        individual/Mapper.cpp
        individual/Phenotype.cpp
        language/parser/BnfRuleParser.cpp
        language/symbol/NonTerminal.cpp
        language/symbol/Option.cpp
        language/symbol/Terminal.cpp
        language/Grammar.cpp
        language/Language.cpp
        population/generator/Generator.cpp
        population/initializer/RandomInitializer.cpp
        population/selector/TournamentSelector.cpp
        population/Population.cpp
        util/bool_generator/TwisterBoolGenerator.cpp
        util/number_generator/TwisterNumberGenerator.cpp
        util/helper.cpp
        Evolution.cpp
        EvolutionBuilder.cpp
        )

add_library(gram STATIC ${SOURCE_FILES})
