#include <gtest/gtest.h>

#include <gram/individual/fitness/ParabolaFitnessCalculator.h>

using namespace gram::individual;

TEST(parabola_fitness_calculator_test, test_exact_match_has_best_possible_fitness) {
  ParabolaFitnessCalculator calculator(10);

  double fitness = calculator.calculate(42, 42);

  ASSERT_NEAR(0.0, fitness, 0.0001);
}

TEST(parabola_fitness_calculator_test, test_opposite_values_have_the_same_fitness) {
  ParabolaFitnessCalculator calculator(10);

  double fitness1 = calculator.calculate(30, 20);
  double fitness2 = calculator.calculate(30, 40);

  ASSERT_NEAR(fitness1, fitness2, 0.0001);
}

TEST(parabola_fitness_calculator_test, test_bad_result_has_bad_fitness) {
  ParabolaFitnessCalculator calculator(10);

  double fitness = calculator.calculate(42, 5);

  ASSERT_GT(fitness, 10.0);
}
