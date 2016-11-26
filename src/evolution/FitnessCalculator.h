#ifndef GRAM_EVOLUTION_FITNESS_CALCULATOR
#define GRAM_EVOLUTION_FITNESS_CALCULATOR

namespace gram {
namespace evolution {
/**
 * Class.
 */
class FitnessCalculator {
 public:
  FitnessCalculator(double width);
  double calculate(int desired, int actual);
 private:
  double width;
};
}
}

#endif // GRAM_EVOLUTION_FITNESS_CALCULATOR
