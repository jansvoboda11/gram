#include <gtest/gtest.h>
#include <gtest/fakeit.hpp>

#include <gram/population/initializer/RandomInitializer.h>

using namespace fakeit;
using namespace gram;
using namespace std;

TEST(random_initializer_test, test_it_initializes_individuals) {
  Mock<Grammar> grammarMock;
  Fake(Dtor(grammarMock));
  When(Method(grammarMock, expand)).AlwaysReturn(Phenotype());
  auto grammar = shared_ptr<Grammar>(&grammarMock.get());

  Genotype genotype1({0, 1, 2});
  Genotype genotype2({3, 0, 1});
  Genotype genotype3({2, 3, 0});

  Individual individual1(genotype1, grammar);
  Individual individual2(genotype2, grammar);
  Individual individual3(genotype3, grammar);

  Mock<NumberGenerator> numberGeneratorMock;
  Fake(Dtor(numberGeneratorMock));
  When(Method(numberGeneratorMock, generateMany))
      .Return(vector<unsigned long>({0, 1, 2}))
      .Return(vector<unsigned long>({3, 0, 1}))
      .Return(vector<unsigned long>({2, 3, 0}));
  auto numberGenerator = unique_ptr<NumberGenerator>(&numberGeneratorMock.get());

  Mock<Reproducer> reproducerMock;
  Fake(Dtor(reproducerMock));
  auto reproducer = shared_ptr<Reproducer>(&reproducerMock.get());

  RandomInitializer initializer(move(numberGenerator), grammar, 3);

  Population population = initializer.initialize(3, reproducer);

  ASSERT_EQ(0, population.number());
  ASSERT_EQ(3, population.size());
  ASSERT_EQ(individual1, population[0]);
  ASSERT_EQ(individual2, population[1]);
  ASSERT_EQ(individual3, population[2]);
}
