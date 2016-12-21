#ifndef GRAM_INDIVIDUAL_FITNESS_CALCULATOR
#define GRAM_INDIVIDUAL_FITNESS_CALCULATOR

namespace gram {
namespace individual {
/**
 * Interface.
 */
class FitnessCalculator {
 public:
  virtual double calculate(int desired, int actual) = 0;
};
}
}

#endif // GRAM_INDIVIDUAL_FITNESS_CALCULATOR
