#include <gtest/gtest.h>
#include <gtest/fakeit.hpp>

#include <gram/individual/Individual.h>

using namespace gram::individual;
using namespace gram::language;

using namespace fakeit;

TEST(individual_test, test_it_mates_with_another_individual) {
  //
}

TEST(individual_test, test_it_undergoes_mutation) {
  //
}

TEST(individual_test, test_it_serializes) {
  //
}

TEST(individual_test, test_it_returns_valid_fitness) {
  Mock<Language> languageMock;
  Fake(Dtor(languageMock));
  When(Method(languageMock, expand)).Return(Phenotype());
  auto language = std::shared_ptr<Language>(&languageMock.get());

  Genotype genotype{0};

  Individual individual(genotype, language);

  individual.setFitness(1.5);
  double fitness = individual.getFitness();

  ASSERT_EQ(1.5, fitness);
}

TEST(individual_test, test_it_rejects_negative_fitness) {
  Mock<Language> languageMock;
  Fake(Dtor(languageMock));
  When(Method(languageMock, expand)).Return(Phenotype());
  auto language = std::shared_ptr<Language>(&languageMock.get());

  Genotype genotype{0};

  Individual individual(genotype, language);

  ASSERT_THROW(individual.setFitness(-1), std::logic_error);
}

TEST(individual_test, test_it_does_not_return_fitness_if_not_calculated) {
  Mock<Language> languageMock;
  Fake(Dtor(languageMock));
  When(Method(languageMock, expand)).Return(Phenotype());
  auto language = std::shared_ptr<Language>(&languageMock.get());

  Genotype genotype{0};

  Individual individual(genotype, language);

  ASSERT_THROW(individual.getFitness(), std::logic_error);
}

TEST(individual_test, test_it_recognizes_two_equal_objects) {
  Mock<Language> languageMock;
  Fake(Dtor(languageMock));
  When(Method(languageMock, expand)).AlwaysReturn(Phenotype());
  auto language = std::shared_ptr<Language>(&languageMock.get());

  Genotype genotype{1, 2, 3};

  Individual individual1(genotype, language);
  Individual individual2(genotype, language);

  ASSERT_TRUE(individual1 == individual2);
}

TEST(individual_test, test_it_recognizes_two_different_objects) {
  Mock<Language> languageMock;
  Fake(Dtor(languageMock));
  When(Method(languageMock, expand)).AlwaysReturn(Phenotype());
  auto language = std::shared_ptr<Language>(&languageMock.get());

  Genotype genotype1{1, 2, 3};
  Genotype genotype2{3, 2, 1};

  Individual individual1(genotype1, language);
  Individual individual2(genotype2, language);

  ASSERT_TRUE(individual1 != individual2);
}
