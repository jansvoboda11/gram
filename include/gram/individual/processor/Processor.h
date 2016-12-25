#ifndef GRAM_INDIVIDUAL_PROCESSOR
#define GRAM_INDIVIDUAL_PROCESSOR

#include <string>

#include <gram/language/Evaluator.h>
#include <gram/individual/fitness/FitnessCalculator.h>

namespace gram {
/**
 * Class.
 */
class Processor {
 public:
  Processor(Evaluator &evaluator, FitnessCalculator &calculator);
  double process(std::string program, int goal);
 private:
  Evaluator &evaluator;
  FitnessCalculator &calculator;
};
}

#endif // GRAM_INDIVIDUAL_PROCESSOR
