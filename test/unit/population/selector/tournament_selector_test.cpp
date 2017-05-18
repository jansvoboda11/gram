#include "gram/population/selector/TournamentSelector.h"

#include <catch.hpp>
#include <fakeit.hpp>

#include "gram/error/NoIndividuals.h"
#include "gram/individual/comparer/LowFitnessComparer.h"

using namespace fakeit;
using namespace gram;
using namespace std;

TEST_CASE("tournament rejects invalid tournament size", "[tournament_selector]") {
  Mock<NumberGenerator> numberGeneratorMock;
  Fake(Dtor(numberGeneratorMock));
  auto numberGenerator = unique_ptr<NumberGenerator>(&numberGeneratorMock.get());

  auto comparer = make_unique<LowFitnessComparer>();

  REQUIRE_THROWS_AS(TournamentSelector(0, move(numberGenerator), move(comparer)), NoIndividuals);
}

TEST_CASE("tournament selector handles empty population", "[tournament_selector]") {
  Mock<NumberGenerator> numberGeneratorMock;
  Fake(Dtor(numberGeneratorMock));
  auto numberGenerator = unique_ptr<NumberGenerator>(&numberGeneratorMock.get());

  auto comparer = make_unique<LowFitnessComparer>();

  Individuals individuals;

  TournamentSelector selector(2, move(numberGenerator), move(comparer));

  REQUIRE_THROWS_AS(selector.select(individuals), NoIndividuals);
}

TEST_CASE("tournament selector chooses the only individual", "[tournament_selector]") {
  Mock<NumberGenerator> numberGeneratorMock;
  Fake(Dtor(numberGeneratorMock));
  When(Method(numberGeneratorMock, generate)).AlwaysReturn(0);
  auto numberGenerator = unique_ptr<NumberGenerator>(&numberGeneratorMock.get());

  auto comparer = make_unique<LowFitnessComparer>();

  Individual individual(Genotype({0}));
  individual.assignFitness(1.0);

  Individuals individuals;
  individuals.addIndividual(individual);

  TournamentSelector selector(2, move(numberGenerator), move(comparer));

  REQUIRE(selector.select(individuals) == individual);
}

TEST_CASE("tournament selector chooses the best individual from randomly selected group", "[tournament_selector]") {
  Mock<NumberGenerator> numberGeneratorMock;
  Fake(Dtor(numberGeneratorMock));
  When(Method(numberGeneratorMock, generate)).Return(1).Return(3);
  auto numberGenerator = unique_ptr<NumberGenerator>(&numberGeneratorMock.get());

  auto comparer = make_unique<LowFitnessComparer>();

  Individual individual1(Genotype({0}));
  Individual individual2(Genotype({0}));
  Individual individual3(Genotype({0}));
  Individual individual4(Genotype({0}));

  individual1.assignFitness(0.0);
  individual2.assignFitness(1.0);
  individual3.assignFitness(2.0);
  individual4.assignFitness(3.0);

  Individuals individuals;
  individuals.addIndividual(individual1);
  individuals.addIndividual(individual2);
  individuals.addIndividual(individual3);
  individuals.addIndividual(individual4);

  TournamentSelector selector(2, move(numberGenerator), move(comparer));

  REQUIRE(selector.select(individuals) == individual2);
}
