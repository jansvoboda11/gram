#ifndef GRAM_POPULATION_PROCESSOR
#define GRAM_POPULATION_PROCESSOR

#include <gram/population/Population.h>
#include <gram/individual/Mapper.h>
#include <gram/language/Evaluator.h>
#include <gram/evolution/fitness_calculator/FitnessCalculator.h>

namespace gram {
namespace population {
/**
 * Class.
 */
class Processor {
 public:
  Processor(gram::individual::Mapper &mapper,
            gram::language::Evaluator &evaluator,
            gram::evolution::FitnessCalculator &calculator);
  void process(Population &population);
 private:
  gram::individual::Mapper &mapper;
  gram::language::Evaluator &evaluator;
  gram::evolution::FitnessCalculator &calculator;
};
}
}

#endif // GRAM_POPULATION_PROCESSOR
