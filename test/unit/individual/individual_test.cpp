#include "gram/individual/Individual.h"

#include <catch.hpp>
#include <fakeit.hpp>

#include "gram/error/FitnessNotCalculated.h"
#include "gram/evaluation/Evaluator.h"
#include "gram/individual/Genotype.h"
#include "gram/operator/crossover/Crossover.h"
#include "gram/operator/mutation/Mutation.h"

using namespace fakeit;
using namespace gram;
using namespace std;

TEST_CASE("individual mates with another individual", "[individual]") {
  Genotype genotype1({0, 0, 0});
  Genotype genotype2({1, 1, 1});
  Genotype expectedGenotype({0, 0, 1});

  Individual individual1(genotype1);
  Individual individual2(genotype2);
  Individual expectedChild(expectedGenotype);

  Mock<Crossover> crossoverMock;
  When(Method(crossoverMock, apply)).Return(Genotype({0, 0, 1}));
  Crossover& crossover = crossoverMock.get();

  Individual child = individual1.mateWith(individual2, crossover);

  REQUIRE(child == expectedChild);
}

TEST_CASE("individual undergoes mutation", "[individual]") {
  Genotype genotype({0, 0, 0});
  Genotype expectedGenotype({0, 1, 0});

  Individual individual(genotype);
  Individual expectedIndividual(expectedGenotype);

  Mock<Mutation> mutation;
  When(Method(mutation, apply)).Return(Genotype({0, 1, 0}));

  individual.mutate(mutation.get());

  REQUIRE(individual == expectedIndividual);
}

TEST_CASE("individual does not return fitness if it was not calculated yet", "[individual]") {
  Genotype genotype({0});

  Individual individual(genotype);

  REQUIRE_THROWS_AS(individual.fitness(), FitnessNotCalculated);
}

TEST_CASE("individual returns fitness if it was assigned", "[individual]") {
  Individual individual(Genotype({0}));

  individual.assignFitness(42.0);

  REQUIRE(individual.hasFitnessCalculated() == true);
  REQUIRE(individual.fitness() == 42.0);
}

TEST_CASE("individual can be serialized", "[individual]") {
  Mock<Mapper> mapperMock;
  When(Method(mapperMock, map)).Return("hello world");
  Mapper& mapper = mapperMock.get();

  Genotype genotype({0});

  Individual individual(genotype);

  REQUIRE(individual.serialize(mapper) == "hello world");
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
