#include <gtest/gtest.h>

#include <gram/population/Initializer.h>
#include <gram/fake/util/FakeNumberGenerator.h>

using namespace gram::population;
using namespace gram::population::individual;
using namespace gram::fake::util;

TEST(initializer_test, test_it_initializes_individuals_with_random_genotype) {
  FakeNumberGenerator numberGenerator{0, 1, 2, 3};

  Genotype firstGenotype{0, 1, 2};
  Genotype secondGenotype{3, 0, 1};
  Genotype thirdGenotype{2, 3, 0};

  Individual firstIndividual(firstGenotype);
  Individual secondIndividual(secondGenotype);
  Individual thirdIndividual(thirdGenotype);

  Initializer initializer(numberGenerator, 3);
  Population population = initializer.initialize(3);

  ASSERT_EQ(firstIndividual, population[0]);
  ASSERT_EQ(secondIndividual, population[1]);
  ASSERT_EQ(thirdIndividual, population[2]);
}
