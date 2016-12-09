#ifndef GRAM_EVOLUTION_FITNESS_CALCULATOR_PARABOLA
#define GRAM_EVOLUTION_FITNESS_CALCULATOR_PARABOLA

#include <gram/evolution/fitness_calculator/FitnessCalculator.h>

namespace gram {
namespace evolution {
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
}

#endif // GRAM_EVOLUTION_FITNESS_CALCULATOR_PARABOLA
