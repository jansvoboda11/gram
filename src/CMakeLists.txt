include_directories(../include)

find_package(Threads REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -pg")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

set(SOURCE_FILES
        error/FitnessNotCalculated.cpp
        error/InvalidGrammar.cpp
        error/InvalidProbability.cpp
        error/NoIndividuals.cpp
        error/WrappingLimitExceeded.cpp
        error/ZeroGenotypeLength.cpp
        evaluation/driver/MultiThreadDriver.cpp
        evaluation/driver/SingleThreadDriver.cpp
        evaluation/EvaluatorCache.cpp
        individual/Individual.cpp
        language/parser/BnfRuleParser.cpp
        language/symbol/NonTerminal.cpp
        language/symbol/Option.cpp
        language/symbol/Rule.cpp
        language/symbol/Symbol.cpp
        language/symbol/Terminal.cpp
        language/grammar/ContextFreeGrammar.cpp
        language/mapper/ContextFreeMapper.cpp
        operator/crossover/OnePointCrossover.cpp
        operator/mutation/BernoulliStepGenerator.cpp
        operator/mutation/CodonMutation.cpp
        operator/selector/comparer/HighFitnessComparer.cpp
        operator/selector/comparer/LowFitnessComparer.cpp
        operator/selector/TournamentSelector.cpp
        population/initializer/RandomInitializer.cpp
        population/reproducer/PassionateReproducer.cpp
        population/Individuals.cpp
        population/Population.cpp
        random/bool_generator/BoolGenerator.cpp
        random/number_generator/NumberGenerator.cpp
        util/logger/NullLogger.cpp
        util/helper.cpp
        util/Probability.cpp
        Evolution.cpp
        ../include/gram/error/FitnessNotCalculated.h
        ../include/gram/error/InvalidGrammar.h
        ../include/gram/error/InvalidProbability.h
        ../include/gram/error/NoIndividuals.h
        ../include/gram/error/WrappingLimitExceeded.h
        ../include/gram/error/ZeroGenotypeLength.h
        ../include/gram/evaluation/driver/EvaluationDriver.h
        ../include/gram/evaluation/driver/MultiThreadDriver.h
        ../include/gram/evaluation/driver/SingleThreadDriver.h
        ../include/gram/evaluation/EvaluatorCache.h
        ../include/gram/evaluation/Evaluator.h
        ../include/gram/operator/crossover/Crossover.h
        ../include/gram/operator/crossover/OnePointCrossover.h
        ../include/gram/operator/mutation/BernoulliStepGenerator.h
        ../include/gram/operator/mutation/CodonMutation.h
        ../include/gram/operator/mutation/Mutation.h
        ../include/gram/operator/selector/comparer/HighFitnessComparer.h
        ../include/gram/operator/selector/comparer/IndividualComparer.h
        ../include/gram/operator/selector/comparer/LowFitnessComparer.h
        ../include/gram/operator/selector/IndividualSelector.h
        ../include/gram/operator/selector/TournamentSelector.h
        ../include/gram/individual/Fitness.h
        ../include/gram/individual/Genotype.h
        ../include/gram/individual/Individual.h
        ../include/gram/individual/Phenotype.h
        ../include/gram/language/grammar/ContextFreeGrammar.h
        ../include/gram/language/mapper/ContextFreeMapper.h
        ../include/gram/language/mapper/Mapper.h
        ../include/gram/language/parser/RuleParser.h
        ../include/gram/language/parser/BnfRuleParser.h
        ../include/gram/language/symbol/NonTerminal.h
        ../include/gram/language/symbol/Option.h
        ../include/gram/language/symbol/Rule.h
        ../include/gram/language/symbol/Symbol.h
        ../include/gram/language/symbol/Terminal.h
        ../include/gram/population/initializer/Initializer.h
        ../include/gram/population/initializer/RandomInitializer.h
        ../include/gram/population/reproducer/PassionateReproducer.h
        ../include/gram/population/reproducer/Reproducer.h
        ../include/gram/population/Individuals.h
        ../include/gram/population/Population.h
        ../include/gram/random/bool_generator/BoolGenerator.h
        ../include/gram/random/number_generator/StdNumberGenerator.h
        ../include/gram/random/number_generator/NumberGenerator.h
        ../include/gram/util/logger/Logger.h
        ../include/gram/util/logger/NullLogger.h
        ../include/gram/util/helper.h
        ../include/gram/util/Probability.h
        ../include/gram/Evolution.h
        )

add_library(gram STATIC ${SOURCE_FILES})

target_link_libraries(gram ${CMAKE_THREAD_LIBS_INIT})
