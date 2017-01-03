#include <gtest/gtest.h>
#include <gtest/fakeit.hpp>

#include <gram/individual/Individual.h>

using namespace fakeit;
using namespace gram;
using namespace std;

TEST(individual_test, test_it_mates_with_another_individual) {
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

  ASSERT_EQ(desiredChild, child);
}

TEST(individual_test, test_it_undergoes_mutation) {
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

  ASSERT_EQ(desiredIndividual, individual);
}

TEST(individual_test, test_it_serializes) {
  Terminal terminal("hello");
  Phenotype phenotype;
  phenotype.addTerminal(terminal);

  Mock<Grammar> grammarMock;
  Fake(Dtor(grammarMock));
  When(Method(grammarMock, expand)).Return(phenotype);
  auto grammar = shared_ptr<Grammar>(&grammarMock.get());

  Genotype genotype({0, 0, 0});

  Individual individual(genotype, grammar);

  ASSERT_EQ("hello", individual.serialize());
}

TEST(individual_test, test_it_does_not_return_fitness_if_not_calculated) {
  Mock<Grammar> grammarMock;
  Fake(Dtor(grammarMock));
  When(Method(grammarMock, expand)).Return(Phenotype());
  auto grammar = shared_ptr<Grammar>(&grammarMock.get());

  Genotype genotype({0});

  Individual individual(genotype, grammar);

  ASSERT_THROW(individual.fitness(), logic_error);
}

TEST(individual_test, test_it_recognizes_two_equal_objects) {
  Mock<Grammar> grammarMock;
  Fake(Dtor(grammarMock));
  When(Method(grammarMock, expand)).AlwaysReturn(Phenotype());
  auto grammar = shared_ptr<Grammar>(&grammarMock.get());

  Genotype genotype({1, 2, 3});

  Individual individual1(genotype, grammar);
  Individual individual2(genotype, grammar);

  ASSERT_TRUE(individual1 == individual2);
}

TEST(individual_test, test_it_recognizes_two_different_objects) {
  Mock<Grammar> grammarMock;
  Fake(Dtor(grammarMock));
  When(Method(grammarMock, expand)).AlwaysReturn(Phenotype());
  auto grammar = shared_ptr<Grammar>(&grammarMock.get());

  Genotype genotype1({1, 2, 3});
  Genotype genotype2({3, 2, 1});

  Individual individual1(genotype1, grammar);
  Individual individual2(genotype2, grammar);

  ASSERT_TRUE(individual1 != individual2);
}
