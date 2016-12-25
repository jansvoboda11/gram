#ifndef GRAM_INDIVIDUAL_PARABOLA_FITNESS_CALCULATOR
#define GRAM_INDIVIDUAL_PARABOLA_FITNESS_CALCULATOR

#include <gram/individual/fitness/FitnessCalculator.h>

namespace gram {
/**
 * Class.
 */
class ParabolaFitnessCalculator : public FitnessCalculator {
 public:
  ParabolaFitnessCalculator(double width);
  double calculate(int desired, int actual);
 private:
  double width;
};
}

#endif // GRAM_INDIVIDUAL_PARABOLA_FITNESS_CALCULATOR
