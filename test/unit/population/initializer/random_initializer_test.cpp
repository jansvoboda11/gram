#include <gtest/gtest.h>
#include <gtest/fakeit.hpp>

#include <gram/population/initializer/RandomInitializer.h>

using namespace fakeit;
using namespace gram;
using namespace std;

TEST(random_initializer_test, test_it_initializes_individuals) {
  Mock<Language> languageMock;
  Fake(Dtor(languageMock));
  When(Method(languageMock, expand)).AlwaysReturn(Phenotype());
  auto language = shared_ptr<Language>(&languageMock.get());

  Genotype genotype1({0, 1, 2});
  Genotype genotype2({3, 0, 1});
  Genotype genotype3({2, 3, 0});

  Individual individual1(genotype1, language);
  Individual individual2(genotype2, language);
  Individual individual3(genotype3, language);

  Mock<NumberGenerator> numberGeneratorMock;
  Fake(Dtor(numberGeneratorMock));
  When(Method(numberGeneratorMock, generateMany))
      .Return(vector<unsigned long>({0, 1, 2}))
      .Return(vector<unsigned long>({3, 0, 1}))
      .Return(vector<unsigned long>({2, 3, 0}));
  auto numberGenerator = unique_ptr<NumberGenerator>(&numberGeneratorMock.get());

  Mock<Generator> generatorMock;
  Fake(Dtor(generatorMock));
  auto generator = shared_ptr<Generator>(&generatorMock.get());

  RandomInitializer initializer(move(numberGenerator), language, 3);

  Population population = initializer.initialize(3, generator);

  ASSERT_EQ(3, population.size());
  ASSERT_EQ(individual1, population[0]);
  ASSERT_EQ(individual2, population[1]);
  ASSERT_EQ(individual3, population[2]);
}
