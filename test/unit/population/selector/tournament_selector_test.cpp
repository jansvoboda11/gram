#include <catch.hpp>
#include <fakeit.hpp>

#include <gram/population/selector/TournamentSelector.h>

using namespace fakeit;
using namespace gram;
using namespace std;

TEST_CASE("tournament selector handles empty population", "[tournament_selector]") {
  Mock<NumberGenerator> numberGeneratorMock;
  Fake(Dtor(numberGeneratorMock));
  auto numberGenerator = unique_ptr<NumberGenerator>(&numberGeneratorMock.get());

  Individuals individuals;

  TournamentSelector selector(2, move(numberGenerator));

  REQUIRE_THROWS_AS(selector.select(individuals), logic_error);
}

TEST_CASE("tournament selector chooses the only individual", "[tournament_selector]") {
  Mock<NumberGenerator> numberGeneratorMock;
  Fake(Dtor(numberGeneratorMock));
  auto numberGenerator = unique_ptr<NumberGenerator>(&numberGeneratorMock.get());

  Mock<Individual> individualMock;
  Individual individual = individualMock.get();

  Individuals individuals;
  individuals.addIndividual(individual);

  TournamentSelector selector(2, move(numberGenerator));

  REQUIRE(selector.select(individuals) == individual);
}

TEST_CASE("tournament selector chooses the best individual from randomly selected group", "[tournament_selector]") {
  Mock<NumberGenerator> numberGeneratorMock;
  Fake(Dtor(numberGeneratorMock));
  When(Method(numberGeneratorMock, generate)).Return(1).Return(3);
  auto numberGenerator = unique_ptr<NumberGenerator>(&numberGeneratorMock.get());

  Mock<Individual> individual1Mock;
  Mock<Individual> individual2Mock;
  Mock<Individual> individual3Mock;
  Mock<Individual> individual4Mock;

  When(Method(individual1Mock, getFitness)).AlwaysReturn(0.0);
  When(Method(individual2Mock, getFitness)).AlwaysReturn(1.0);
  When(Method(individual3Mock, getFitness)).AlwaysReturn(2.0);
  When(Method(individual4Mock, getFitness)).AlwaysReturn(3.0);

  Individual individual1 = individual1Mock.get();
  Individual individual2 = individual2Mock.get();
  Individual individual3 = individual3Mock.get();
  Individual individual4 = individual4Mock.get();

  Individuals individuals;
  individuals.addIndividual(individual1);
  individuals.addIndividual(individual2);
  individuals.addIndividual(individual3);
  individuals.addIndividual(individual4);

  TournamentSelector selector(2, move(numberGenerator));

  REQUIRE(selector.select(individuals) == individual2);
}
