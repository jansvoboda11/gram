#include "gram/individual/comparer/LowFitnessComparer.h"

#include <catch.hpp>
#include <fakeit.hpp>

#include "gram/individual/Individual.h"

using namespace fakeit;
using namespace gram;

TEST_CASE("low fitness comparer chooses the right individual", "[low_fitness_comparer]") {
  Mock<Individual> individual1Mock;
  When(Method(individual1Mock, hasFitnessCalculated)).AlwaysReturn(true);
  When(Method(individual1Mock, fitness)).Return(1.0);
  Individual& individual1(individual1Mock.get());

  Mock<Individual> individual2Mock;
  When(Method(individual2Mock, hasFitnessCalculated)).AlwaysReturn(true);
  When(Method(individual2Mock, fitness)).Return(2.0);
  Individual& individual2(individual2Mock.get());

  LowFitnessComparer comparer;

  REQUIRE(comparer.isFirstFitter(individual1, individual2) == true);
}

TEST_CASE("low fitness comparer chooses individual with calculated fitness", "[low_fitness_comparer]") {
  Mock<Individual> individual1Mock;
  When(Method(individual1Mock, hasFitnessCalculated)).AlwaysReturn(true);
  When(Method(individual1Mock, fitness)).Return(100.0);
  Individual& individual1(individual1Mock.get());

  Mock<Individual> individual2Mock;
  When(Method(individual2Mock, hasFitnessCalculated)).AlwaysReturn(false);
  Individual& individual2(individual2Mock.get());

  LowFitnessComparer comparer;

  REQUIRE(comparer.isFirstFitter(individual1, individual2) == true);
}
