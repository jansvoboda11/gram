#include <catch.hpp>

#include <gram/individual/mutation/BernoulliDistributionStepGenerator.h>
#include <gram/random/number_generator/XorShiftNumberGenerator.h>

using namespace gram;
using namespace std;

TEST_CASE("Bernoulli distribution step generator generates statistically good steps",
          "[bernoulli_distribution_step_generator") {
  unsigned long testSize = 1000000;

  auto numberGenerator = make_unique<XorShiftNumberGenerator>();

  BernoulliDistributionStepGenerator stepGenerator(0.5, move(numberGenerator));

  unsigned long totalSteps = 0;

  for (unsigned long i = 0; i < testSize; i++) {
    totalSteps += stepGenerator.generateStep();
  }

  REQUIRE(totalSteps > testSize * 0.99);
  REQUIRE(totalSteps < testSize * 1.01);
}
