#include <catch.hpp>
#include <fakeit.hpp>

#include <gram/population/Individuals.h>

using namespace fakeit;
using namespace gram;
using namespace std;

TEST_CASE("individuals throw when empty and choosing the best individual", "[individuals]") {
  Individuals individuals;

  REQUIRE_THROWS_AS(individuals.bestIndividual(), logic_error);
}

TEST_CASE("individuals choose the best individual", "[individuals]") {
  Mock<Individual> individual1Mock;
  Mock<Individual> individual2Mock;
  Mock<Individual> individual3Mock;

  When(Method(individual1Mock, getFitness)).AlwaysReturn(1.0);
  When(Method(individual2Mock, getFitness)).AlwaysReturn(0.5);
  When(Method(individual3Mock, getFitness)).AlwaysReturn(2.0);

  Individual individual1 = individual1Mock.get();
  Individual individual2 = individual2Mock.get();
  Individual individual3 = individual3Mock.get();

  Individuals individuals;
  individuals.addIndividual(individual1);
  individuals.addIndividual(individual2);
  individuals.addIndividual(individual3);

  REQUIRE(individuals.bestIndividual() == individual2);
}
