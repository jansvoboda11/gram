#include <catch.hpp>
#include <fakeit.hpp>

#include <gram/individual/Individual.h>

using namespace fakeit;
using namespace gram;
using namespace std;

TEST_CASE("individual mates with another individual", "[individual]") {
  Genotype genotype1({0, 0, 0});
  Genotype genotype2({1, 1, 1});
  Genotype desiredGenotype({0, 0, 1});

  Individual individual1(genotype1);
  Individual individual2(genotype2);
  Individual desiredChild(desiredGenotype);

  Mock<Crossover> crossover;
  When(Method(crossover, apply)).Return(Genotype({0, 0, 1}));

  Individual child = individual1.mateWith(individual2, crossover.get());

  REQUIRE(desiredChild == child);
}

TEST_CASE("individual undergoes mutation", "[individual]") {
  Genotype genotype({0, 0, 0});
  Genotype desiredGenotype({0, 1, 0});

  Individual individual(genotype);
  Individual desiredIndividual(desiredGenotype);

  Mock<Mutation> mutation;
  When(Method(mutation, apply)).Return(Genotype({0, 1, 0}));

  individual.mutate(mutation.get());

  REQUIRE(desiredIndividual == individual);
}

TEST_CASE("individual does not return fitness if it was not calculated yet", "[individual]") {
  Genotype genotype({0});

  Individual individual(genotype);

  REQUIRE_THROWS_AS(individual.getFitness(), logic_error);
}

TEST_CASE("same individuals are equal", "[individual]") {
  Genotype genotype({1, 2, 3});

  Individual individual1(genotype);
  Individual individual2(genotype);

  REQUIRE(individual1 == individual2);
}

TEST_CASE("different individuals are not equal", "[individual]") {
  Genotype genotype1({1, 2, 3});
  Genotype genotype2({3, 2, 1});

  Individual individual1(genotype1);
  Individual individual2(genotype2);

  REQUIRE(individual1 != individual2);
}
