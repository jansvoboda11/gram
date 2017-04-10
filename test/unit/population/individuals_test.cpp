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

  auto sharedIndividual1 = make_shared<Individual>(individual1);
  auto sharedIndividual2 = make_shared<Individual>(individual2);
  auto sharedIndividual3 = make_shared<Individual>(individual3);

  Individuals individuals;
  individuals.addIndividual(sharedIndividual1);
  individuals.addIndividual(sharedIndividual2);
  individuals.addIndividual(sharedIndividual3);

  REQUIRE(individuals.bestIndividual() == individual2);
}
