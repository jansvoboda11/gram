#ifndef GRAM_EVOLUTION_FITNESS_CALCULATOR_MOCK
#define GRAM_EVOLUTION_FITNESS_CALCULATOR_MOCK

#include <gmock/gmock.h>

#include <gram/evolution/fitness_calculator/FitnessCalculator.h>

namespace gram {
namespace evolution {
/**
 * Mock.
 */
class FitnessCalculatorMock : public FitnessCalculator {
 public:
  MOCK_METHOD2(calculate, double(int desired, int actual));
};
}
}

#endif // GRAM_EVOLUTION_FITNESS_CALCULATOR_MOCK
