#include <gtest/gtest.h>

#include <gram/individual/Individual.h>

#include "../../lib/fakeit/fakeit.hpp"

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
  Terminal terminal("hello");
  Phenotype phenotype;
  phenotype.addTerminal(terminal);
  Mock<Language> languageMock;
  Fake(Dtor(languageMock));
  When(Method(languageMock, expand)).Return(phenotype);
  auto language = std::shared_ptr<Language>(&languageMock.get());

  Genotype genotype{0};

  Individual individual(genotype, language);

  individual.setFitness(1.5);
  double fitness = individual.getFitness();

  ASSERT_EQ(1.5, fitness);
}

TEST(individual_test, test_it_rejects_negative_fitness) {
  Terminal terminal("hello");
  Phenotype phenotype;
  phenotype.addTerminal(terminal);
  Mock<Language> languageMock;
  Fake(Dtor(languageMock));
  When(Method(languageMock, expand)).Return(phenotype);
  auto language = std::shared_ptr<Language>(&languageMock.get());

  Genotype genotype{0};

  Individual individual(genotype, language);

  ASSERT_THROW(individual.setFitness(-1), std::logic_error);
}

TEST(individual_test, test_it_does_not_return_fitness_if_not_calculated) {
  Terminal terminal("hello");
  Phenotype phenotype;
  phenotype.addTerminal(terminal);
  Mock<Language> languageMock;
  Fake(Dtor(languageMock));
  When(Method(languageMock, expand)).Return(phenotype);
  auto language = std::shared_ptr<Language>(&languageMock.get());

  Genotype genotype{0};

  Individual individual(genotype, language);

  ASSERT_THROW(individual.getFitness(), std::logic_error);
}

TEST(individual_test, test_it_recognizes_two_equal_objects) {
  Terminal terminal("hello");
  Phenotype phenotype;
  phenotype.addTerminal(terminal);
  Mock<Language> languageMock;
  Fake(Dtor(languageMock));
  When(Method(languageMock, expand)).Return(phenotype).Return(phenotype);
  auto language = std::shared_ptr<Language>(&languageMock.get());

  Genotype genotype{1, 2, 3};

  Individual individual1(genotype, language);
  Individual individual2(genotype, language);

  ASSERT_TRUE(individual1 == individual2);
}

TEST(individual_test, test_it_recognizes_two_different_objects) {
  Terminal hello("hello");
  Terminal world("world");
  Phenotype phenotype1;
  Phenotype phenotype2;
  phenotype1.addTerminal(hello);
  phenotype2.addTerminal(world);
  Mock<Language> languageMock;
  Fake(Dtor(languageMock));
  When(Method(languageMock, expand)).Return(phenotype1).Return(phenotype2);
  auto language = std::shared_ptr<Language>(&languageMock.get());

  Genotype genotype1{1, 2, 3};
  Genotype genotype2{3, 2, 1};

  Individual individual1(genotype1, language);
  Individual individual2(genotype2, language);

  ASSERT_TRUE(individual1 != individual2);
}
