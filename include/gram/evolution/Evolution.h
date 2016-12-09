#ifndef GRAM_EVOLUTION_EVOLUTION
#define GRAM_EVOLUTION_EVOLUTION

#include <gram/evolution/operator/Crossover.h>
#include <gram/evolution/operator/Mutation.h>
#include <gram/evolution/selector/IndividualSelector.h>
#include <gram/evolution/fitness_calculator/FitnessCalculator.h>
#include <gram/individual/Individual.h>
#include <gram/individual/Mapper.h>
#include <gram/language/Evaluator.h>
#include <gram/population/initializer/Initializer.h>
#include <gram/population/Population.h>
#include <gram/util/NumberGenerator.h>
#include <gram/population/generator/Generator.h>

namespace gram {
namespace evolution {
/**
 * Class.
 */
class Evolution {
 public:
  gram::individual::Individual run(int populationSize, int iterationCount);
  void setGenerator(gram::population::Generator *newGenerator);
  void setEvaluator(gram::language::Evaluator *newEvaluator);
  void setCalculator(FitnessCalculator *newCalculator);
  void setMapper(gram::individual::Mapper *newMapper);
  void setInitializer(gram::population::Initializer *newInitializer);
 private:
  gram::population::Generator *generator;
  gram::language::Evaluator *evaluator;
  FitnessCalculator *calculator;
  gram::individual::Mapper *mapper;
  gram::population::Initializer *initializer;
  void processGeneration(gram::population::Population &population);
};
}
}

#endif // GRAM_EVOLUTION_EVOLUTION
