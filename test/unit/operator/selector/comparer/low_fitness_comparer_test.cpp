#include "gram/operator/selector/comparer/LowFitnessComparer.h"

#include <catch.hpp>
#include <fakeit.hpp>

#include "gram/individual/Fitness.h"
#include "gram/individual/Individual.h"

using namespace fakeit;
using namespace gram;

TEST_CASE("low fitness comparer chooses the right individual", "[low_fitness_comparer]") {
  Individual individual1(Genotype({0}));
  Individual individual2(Genotype({0}));

  individual1.assignFitness(Fitness(1.0));
  individual2.assignFitness(Fitness(2.0));

  LowFitnessComparer comparer;

  REQUIRE(comparer.isFirstFitter(individual1, individual2) == true);
}

TEST_CASE("low fitness comparer chooses individual with calculated fitness", "[low_fitness_comparer]") {
  Individual individual1(Genotype({0}));
  Individual individual2(Genotype({0}));

  individual1.assignFitness(Fitness(100.0));

  LowFitnessComparer comparer;

  REQUIRE(comparer.isFirstFitter(individual1, individual2) == true);
}
