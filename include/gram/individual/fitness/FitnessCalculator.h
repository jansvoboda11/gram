#ifndef GRAM_EVOLUTION_FITNESS_CALCULATOR
#define GRAM_EVOLUTION_FITNESS_CALCULATOR

namespace gram {
namespace evolution {
/**
 * Interface.
 */
class FitnessCalculator {
 public:
  virtual double calculate(int desired, int actual) = 0;
};
}
}

#endif // GRAM_EVOLUTION_FITNESS_CALCULATOR
