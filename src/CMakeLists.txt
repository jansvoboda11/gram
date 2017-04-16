include_directories(../include)

find_package(Threads REQUIRED)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O3")

set(SOURCE_FILES
        evaluation/driver/MultiThreadDriver.cpp
        evaluation/driver/SingleThreadDriver.cpp
        individual/comparer/HighFitnessComparer.cpp
        individual/comparer/LowFitnessComparer.cpp
        individual/crossover/OnePointCrossover.cpp
        individual/mutation/BernoulliDistributionStepGenerator.cpp
        individual/mutation/CodonMutation.cpp
        individual/mutation/FastCodonMutation.cpp
        individual/Individual.cpp
        language/parser/BnfRuleParser.cpp
        language/symbol/NonTerminal.cpp
        language/symbol/Option.cpp
        language/symbol/Rule.cpp
        language/symbol/Symbol.cpp
        language/symbol/Terminal.cpp
        language/grammar/ContextFreeGrammar.cpp
        language/mapper/ContextFreeMapper.cpp
        population/initializer/RandomInitializer.cpp
        population/reproducer/PassionateReproducer.cpp
        population/selector/TournamentSelector.cpp
        population/Individuals.cpp
        population/Population.cpp
        random/bool_generator/BoolGenerator.cpp
        random/number_generator/NumberGenerator.cpp
        random/number_generator/XorShiftNumberGenerator.cpp
        util/logger/NullLogger.cpp
        util/helper.cpp
        Evolution.cpp
        ../include/gram/evaluation/driver/EvaluationDriver.h
        ../include/gram/evaluation/driver/MultiThreadDriver.h
        ../include/gram/evaluation/driver/SingleThreadDriver.h
        ../include/gram/evaluation/Evaluator.h
        ../include/gram/individual/comparer/HighFitnessComparer.h
        ../include/gram/individual/comparer/IndividualComparer.h
        ../include/gram/individual/comparer/LowFitnessComparer.h
        ../include/gram/individual/crossover/Crossover.h
        ../include/gram/individual/crossover/OnePointCrossover.h
        ../include/gram/individual/mutation/BernoulliDistributionStepGenerator.h
        ../include/gram/individual/mutation/CodonMutation.h
        ../include/gram/individual/mutation/FastCodonMutation.h
        ../include/gram/individual/mutation/Mutation.h
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
        ../include/gram/population/selector/IndividualSelector.h
        ../include/gram/population/selector/TournamentSelector.h
        ../include/gram/population/Individuals.h
        ../include/gram/population/Population.h
        ../include/gram/random/bool_generator/BoolGenerator.h
        ../include/gram/random/number_generator/StdNumberGenerator.h
        ../include/gram/random/number_generator/NumberGenerator.h
        ../include/gram/random/number_generator/XorShiftNumberGenerator.h
        ../include/gram/util/logger/Logger.h
        ../include/gram/util/logger/NullLogger.h
        ../include/gram/util/helper.h
        ../include/gram/Evolution.h
        )

add_library(gram STATIC ${SOURCE_FILES})

target_link_libraries(gram ${CMAKE_THREAD_LIBS_INIT})
