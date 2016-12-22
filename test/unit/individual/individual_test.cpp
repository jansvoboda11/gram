#include <gtest/gtest.h>
#include <gtest/fakeit.hpp>

#include <gram/individual/Individual.h>

using namespace gram::individual;
using namespace gram::language;

using namespace fakeit;

TEST(individual_test, test_it_mates_with_another_individual) {
  Mock<Language> languageMock;
  Fake(Dtor(languageMock));
  When(Method(languageMock, expand)).AlwaysReturn(Phenotype());
  auto language = std::shared_ptr<Language>(&languageMock.get());

  Genotype genotype1({0, 0, 0});
  Genotype genotype2({1, 1, 1});

  auto individual1 = std::make_shared<Individual>(genotype1, language);
  auto individual2 = std::make_shared<Individual>(genotype2, language);

  Mock<Crossover> crossover;
  When(Method(crossover, apply)).Return(Genotype({0, 0, 1}));

  std::shared_ptr<Individual> child = individual1->mateWith(individual2, crossover.get());

  ASSERT_EQ(Genotype({0, 0, 1}), child->genotype());
}

TEST(individual_test, test_it_undergoes_mutation) {
  Mock<Language> languageMock;
  Fake(Dtor(languageMock));
  When(Method(languageMock, expand)).Return(Phenotype());
  auto language = std::shared_ptr<Language>(&languageMock.get());

  Genotype genotype({0, 0, 0});

  Individual individual(genotype, language);

  Mock<Mutation> mutation;
  When(Method(mutation, apply)).Return(Genotype({0, 1, 0}));

  individual.mutate(mutation.get());

  ASSERT_EQ(Genotype({0, 1, 0}), individual.genotype());
}

TEST(individual_test, test_it_serializes) {
  Mock<Language> languageMock;
  Fake(Dtor(languageMock));
  When(Method(languageMock, serialize)).Return("hello world");
  auto language = std::shared_ptr<Language>(&languageMock.get());

  Genotype genotype({0, 0, 0});

  Individual individual(genotype, language);

  ASSERT_EQ("hello world", individual.serialize());
}

TEST(individual_test, test_it_returns_valid_fitness) {
  Mock<Language> languageMock;
  Fake(Dtor(languageMock));
  When(Method(languageMock, expand)).Return(Phenotype());
  auto language = std::shared_ptr<Language>(&languageMock.get());

  Genotype genotype({0});

  Individual individual(genotype, language);

  individual.setFitness(1.5);

  ASSERT_EQ(1.5, individual.getFitness());
}

TEST(individual_test, test_it_rejects_negative_fitness) {
  Mock<Language> languageMock;
  Fake(Dtor(languageMock));
  When(Method(languageMock, expand)).Return(Phenotype());
  auto language = std::shared_ptr<Language>(&languageMock.get());

  Genotype genotype({0});

  Individual individual(genotype, language);

  ASSERT_THROW(individual.setFitness(-1), std::logic_error);
}

TEST(individual_test, test_it_does_not_return_fitness_if_not_calculated) {
  Mock<Language> languageMock;
  Fake(Dtor(languageMock));
  When(Method(languageMock, expand)).Return(Phenotype());
  auto language = std::shared_ptr<Language>(&languageMock.get());

  Genotype genotype({0});

  Individual individual(genotype, language);

  ASSERT_THROW(individual.getFitness(), std::logic_error);
}

TEST(individual_test, test_it_recognizes_two_equal_objects) {
  Mock<Language> languageMock;
  Fake(Dtor(languageMock));
  When(Method(languageMock, expand)).AlwaysReturn(Phenotype());
  auto language = std::shared_ptr<Language>(&languageMock.get());

  Genotype genotype({1, 2, 3});

  Individual individual1(genotype, language);
  Individual individual2(genotype, language);

  ASSERT_TRUE(individual1 == individual2);
}

TEST(individual_test, test_it_recognizes_two_different_objects) {
  Mock<Language> languageMock;
  Fake(Dtor(languageMock));
  When(Method(languageMock, expand)).AlwaysReturn(Phenotype());
  auto language = std::shared_ptr<Language>(&languageMock.get());

  Genotype genotype1({1, 2, 3});
  Genotype genotype2({3, 2, 1});

  Individual individual1(genotype1, language);
  Individual individual2(genotype2, language);

  ASSERT_TRUE(individual1 != individual2);
}
