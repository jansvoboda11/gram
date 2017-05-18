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

  Individual individual1(Genotype({0}));
  Individual individual2(Genotype({0}));
  Individual individual3(Genotype({0}));

  individual1.assignFitness(1.0);
  individual2.assignFitness(0.5);
  individual3.assignFitness(2.0);

  Individuals individuals;
  individuals.addIndividual(individual1);
  individuals.addIndividual(individual2);
  individuals.addIndividual(individual3);

  REQUIRE(individuals.bestIndividual(comparer) == individual2);
}
