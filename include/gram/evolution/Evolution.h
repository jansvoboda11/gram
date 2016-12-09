#ifndef GRAM_EVOLUTION_EVOLUTION
#define GRAM_EVOLUTION_EVOLUTION

#include <gram/evolution/operator/Crossover.h>
#include <gram/evolution/operator/Mutation.h>
#include <gram/evolution/selector/IndividualSelector.h>
#include <gram/evolution/fitness_calculator/FitnessCalculator.h>
#include <gram/individual/Individual.h>
#include <gram/individual/Mapper.h>
#include <gram/language/Evaluator.h>
#include <gram/population/Initializer.h>
#include <gram/population/Population.h>
#include <gram/util/NumberGenerator.h>

namespace gram {
namespace evolution {
/**
 * Class.
 */
class Evolution {
 public:
  gram::individual::Individual run(int populationSize, int iterationCount);
  void setEvaluator(gram::language::Evaluator *newEvaluator);
  void setCalculator(FitnessCalculator *newCalculator);
  void setSelector(IndividualSelector *newSelector);
  void setMapper(gram::individual::Mapper *newMapper);
  void setInitializer(gram::population::Initializer *newInitializer);
  void setCrossover(Crossover *newCrossover);
  void setMutation(Mutation *newMutation);
 private:
  gram::language::Evaluator *evaluator;
  FitnessCalculator *calculator;
  IndividualSelector *selector;
  gram::individual::Mapper *mapper;
  gram::population::Initializer *initializer;
  Crossover *crossover;
  Mutation *mutation;
  void processGeneration(gram::population::Population &population);
  gram::population::Population generateGeneration(gram::population::Population &population);
};
}
}

#endif // GRAM_EVOLUTION_EVOLUTION
