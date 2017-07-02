#include "gram/operator/mutation/BernoulliStepGenerator.h"

#include <catch.hpp>

#include "gram/random/number_generator/StdNumberGenerator.h"
#include "gram/random/Probability.h"

using namespace gram;
using namespace std;

TEST_CASE("Bernoulli step generator generates statistically good steps", "[bernoulli_step_generator]") {
  unsigned long testSize = 1000000;

  auto numberGenerator = make_unique<StdNumberGenerator<mt19937>>();

  BernoulliStepGenerator stepGenerator(Probability(0.5), move(numberGenerator));

  unsigned long totalSteps = 0;

  for (unsigned long i = 0; i < testSize; i++) {
    totalSteps += stepGenerator.generateStep();
  }

  REQUIRE(totalSteps > testSize * 0.99);
  REQUIRE(totalSteps < testSize * 1.01);
}
