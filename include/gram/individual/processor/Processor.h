#ifndef GRAM_INDIVIDUAL_PROCESSOR
#define GRAM_INDIVIDUAL_PROCESSOR

#include <memory>
#include <string>

#include <gram/individual/fitness/FitnessCalculator.h>
#include <gram/language/Evaluator.h>

namespace gram {
/**
 * Class.
 */
class Processor {
 public:
  Processor(std::unique_ptr<Evaluator> evaluator, std::unique_ptr<FitnessCalculator> fitnessCalculator);
  double process(std::string program, int goal) const;
 private:
  std::unique_ptr<Evaluator> evaluator;
  std::unique_ptr<FitnessCalculator> fitnessCalculator;
};
}

#endif // GRAM_INDIVIDUAL_PROCESSOR
