#ifndef GRAM_INDIVIDUAL_PROCESSOR
#define GRAM_INDIVIDUAL_PROCESSOR

#include <string>

#include <gram/language/Evaluator.h>
#include <gram/individual/fitness/FitnessCalculator.h>

namespace gram {
namespace individual {
/**
 * Class.
 */
class Processor {
 public:
  Processor(gram::language::Evaluator &evaluator, FitnessCalculator &calculator);
  double process(std::string program, int goal);
 private:
  gram::language::Evaluator &evaluator;
  FitnessCalculator &calculator;
};
}
}

#endif // GRAM_INDIVIDUAL_PROCESSOR
