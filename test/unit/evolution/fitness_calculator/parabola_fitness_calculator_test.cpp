#include <gtest/gtest.h>

#include <gram/evolution/fitness_calculator/ParabolaFitnessCalculator.h>

using namespace gram::evolution;

TEST(parabola_fitness_calculator_test, test_exact_match_has_best_possible_fitness) {
  ParabolaFitnessCalculator calculator(10);

  int desired = 42;
  int actual = 42;

  ASSERT_NEAR(0.0, calculator.calculate(desired, actual), 0.0001);
}

TEST(parabola_fitness_calculator_test, test_opposite_values_have_the_same_fitness) {
  ParabolaFitnessCalculator calculator(10);

  int desired = 30;
  int firstActual = 20;
  int secondActual = 40;

  ASSERT_NEAR(calculator.calculate(desired, firstActual), calculator.calculate(desired, secondActual), 0.0001);
}

TEST(parabola_fitness_calculator_test, test_bad_result_has_bad_fitness) {
  ParabolaFitnessCalculator calculator(10);

  int desired = 42;
  int actual = 5;

  ASSERT_GT(calculator.calculate(desired, actual), 10.0);
}
