#include <gtest/gtest.h>
#include <gtest/fakeit.hpp>

#include <gram/individual/Individual.h>

using namespace fakeit;
using namespace gram;
using namespace std;

TEST(individual_test, test_it_mates_with_another_individual) {
  Mock<Language> languageMock;
  Fake(Dtor(languageMock));
  When(Method(languageMock, expand)).AlwaysReturn(Phenotype());
  auto language = shared_ptr<Language>(&languageMock.get());

  Genotype genotype1({0, 0, 0});
  Genotype genotype2({1, 1, 1});

  auto individual1 = make_shared<Individual>(genotype1, language);
  auto individual2 = make_shared<Individual>(genotype2, language);

  Mock<Crossover> crossover;
  When(Method(crossover, apply)).Return(Genotype({0, 0, 1}));

  shared_ptr<Individual> child = individual1->mateWith(individual2, crossover.get());

  Genotype desiredGenotype({0, 0, 1});
  Individual desiredChild(desiredGenotype, language);
  ASSERT_EQ(desiredChild, *child);
}

TEST(individual_test, test_it_undergoes_mutation) {
  Mock<Language> languageMock;
  Fake(Dtor(languageMock));
  When(Method(languageMock, expand)).Return(Phenotype());
  auto language = shared_ptr<Language>(&languageMock.get());

  Genotype genotype({0, 0, 0});

  Individual individual(genotype, language);

  Mock<Mutation> mutation;
  When(Method(mutation, apply)).Return(Genotype({0, 1, 0}));

  individual.mutate(mutation.get());

  Genotype desiredGenotype({0, 1, 0});
  Individual desired(desiredGenotype, language);
  ASSERT_EQ(desired, individual);
}

TEST(individual_test, test_it_serializes) {
  Terminal terminal("hello");
  Phenotype phenotype;
  phenotype.addTerminal(terminal);

  Mock<Language> languageMock;
  Fake(Dtor(languageMock));
  When(Method(languageMock, expand)).Return(phenotype);
  auto language = shared_ptr<Language>(&languageMock.get());

  Genotype genotype({0, 0, 0});

  Individual individual(genotype, language);

  ASSERT_EQ("hello", individual.serialize());
}

TEST(individual_test, test_it_does_not_return_fitness_if_not_calculated) {
  Mock<Language> languageMock;
  Fake(Dtor(languageMock));
  When(Method(languageMock, expand)).Return(Phenotype());
  auto language = shared_ptr<Language>(&languageMock.get());

  Genotype genotype({0});

  Individual individual(genotype, language);

  ASSERT_THROW(individual.fitness(), logic_error);
}

TEST(individual_test, test_it_recognizes_two_equal_objects) {
  Mock<Language> languageMock;
  Fake(Dtor(languageMock));
  When(Method(languageMock, expand)).AlwaysReturn(Phenotype());
  auto language = shared_ptr<Language>(&languageMock.get());

  Genotype genotype({1, 2, 3});

  Individual individual1(genotype, language);
  Individual individual2(genotype, language);

  ASSERT_TRUE(individual1 == individual2);
}

TEST(individual_test, test_it_recognizes_two_different_objects) {
  Mock<Language> languageMock;
  Fake(Dtor(languageMock));
  When(Method(languageMock, expand)).AlwaysReturn(Phenotype());
  auto language = shared_ptr<Language>(&languageMock.get());

  Genotype genotype1({1, 2, 3});
  Genotype genotype2({3, 2, 1});

  Individual individual1(genotype1, language);
  Individual individual2(genotype2, language);

  ASSERT_TRUE(individual1 != individual2);
}
