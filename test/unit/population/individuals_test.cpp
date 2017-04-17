#include "gram/population/Individuals.h"

#include <catch.hpp>
#include <fakeit.hpp>

#include "gram/error/NoIndividuals.h"
#include "gram/individual/comparer/LowFitnessComparer.h"

using namespace fakeit;
using namespace gram;
using namespace std;

TEST_CASE("individuals throw when empty and choosing the best individual", "[individuals]") {
  LowFitnessComparer comparer;

  Individuals individuals;

  REQUIRE_THROWS_AS(individuals.bestIndividual(comparer), NoIndividuals);
}

TEST_CASE("individuals choose individual with the lowest fitness", "[individuals]") {
  LowFitnessComparer comparer;

  Mock<Individual> individual1Mock;
  Mock<Individual> individual2Mock;
  Mock<Individual> individual3Mock;

  When(Method(individual1Mock, fitness)).AlwaysReturn(1.0);
  When(Method(individual2Mock, fitness)).AlwaysReturn(0.5);
  When(Method(individual3Mock, fitness)).AlwaysReturn(2.0);

  Individual individual1 = individual1Mock.get();
  Individual individual2 = individual2Mock.get();
  Individual individual3 = individual3Mock.get();

  Individuals individuals;
  individuals.addIndividual(individual1);
  individuals.addIndividual(individual2);
  individuals.addIndividual(individual3);

  REQUIRE(individuals.bestIndividual(comparer) == individual2);
}
