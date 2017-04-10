#include <catch.hpp>
#include <fakeit.hpp>

#include <gram/individual/Individual.h>

using namespace fakeit;
using namespace gram;
using namespace std;

TEST_CASE("individual mates with another individual", "[individual]") {
  Mock<Grammar> grammarMock;
  Fake(Dtor(grammarMock));
  When(Method(grammarMock, expand)).AlwaysReturn(Phenotype());
  auto grammar = shared_ptr<Grammar>(&grammarMock.get());

  Genotype genotype1({0, 0, 0});
  Genotype genotype2({1, 1, 1});
  Genotype desiredGenotype({0, 0, 1});

  Individual individual1(genotype1, grammar);
  Individual individual2(genotype2, grammar);
  Individual desiredChild(desiredGenotype, grammar);

  Mock<Crossover> crossover;
  When(Method(crossover, apply)).Return(Genotype({0, 0, 1}));

  Individual child = individual1.mateWith(individual2, crossover.get());

  REQUIRE(desiredChild == child);
}

TEST_CASE("individual undergoes mutation", "[individual]") {
  Mock<Grammar> grammarMock;
  Fake(Dtor(grammarMock));
  When(Method(grammarMock, expand)).Return(Phenotype());
  auto grammar = shared_ptr<Grammar>(&grammarMock.get());

  Genotype genotype({0, 0, 0});
  Genotype desiredGenotype({0, 1, 0});

  Individual individual(genotype, grammar);
  Individual desiredIndividual(desiredGenotype, grammar);

  Mock<Mutation> mutation;
  When(Method(mutation, apply)).Return(Genotype({0, 1, 0}));

  individual.mutate(mutation.get());

  REQUIRE(desiredIndividual == individual);
}

TEST_CASE("individual can be serialized", "[individual]") {
  Terminal terminal("hello");
  Phenotype phenotype;
  phenotype.addTerminal(terminal);

  Mock<Grammar> grammarMock;
  Fake(Dtor(grammarMock));
  When(Method(grammarMock, expand)).Return(phenotype);
  auto grammar = shared_ptr<Grammar>(&grammarMock.get());

  Genotype genotype({0, 0, 0});

  Individual individual(genotype, grammar);

  REQUIRE("hello" == individual.serialize());
}

TEST_CASE("individual does not return fitness if it was not calculated yet", "[individual]") {
  Mock<Grammar> grammarMock;
  Fake(Dtor(grammarMock));
  When(Method(grammarMock, expand)).Return(Phenotype());
  auto grammar = shared_ptr<Grammar>(&grammarMock.get());

  Genotype genotype({0});

  Individual individual(genotype, grammar);

  REQUIRE_THROWS_AS(individual.fitness(), logic_error);
}

TEST_CASE("same individuals are equal", "[individual]") {
  Mock<Grammar> grammarMock;
  Fake(Dtor(grammarMock));
  When(Method(grammarMock, expand)).AlwaysReturn(Phenotype());
  auto grammar = shared_ptr<Grammar>(&grammarMock.get());

  Genotype genotype({1, 2, 3});

  Individual individual1(genotype, grammar);
  Individual individual2(genotype, grammar);

  REQUIRE(individual1 == individual2);
}

TEST_CASE("different individuals are not equal", "[individual]") {
  Mock<Grammar> grammarMock;
  Fake(Dtor(grammarMock));
  When(Method(grammarMock, expand)).AlwaysReturn(Phenotype());
  auto grammar = shared_ptr<Grammar>(&grammarMock.get());

  Genotype genotype1({1, 2, 3});
  Genotype genotype2({3, 2, 1});

  Individual individual1(genotype1, grammar);
  Individual individual2(genotype2, grammar);

  REQUIRE(individual1 != individual2);
}
