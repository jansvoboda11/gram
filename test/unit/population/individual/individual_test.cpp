#include <gtest/gtest.h>

#include <population/individual/Genotype.h>
#include <population/individual/Individual.h>

using namespace gram::population::individual;

TEST(individual_test, test_it_recognizes_two_equal_objects) {
  Genotype firstGenotype{1, 2, 3};
  Genotype secondGenotype{1, 2, 3};

  Individual firstIndividual(firstGenotype);
  Individual secondIndividual(secondGenotype);

  ASSERT_TRUE(firstIndividual == secondIndividual);
}

TEST(individual_test, test_it_recognizes_two_different_objects) {
  Genotype firstGenotype{1, 2, 3};
  Genotype secondGenotype{3, 2, 1};

  Individual firstIndividual(firstGenotype);
  Individual secondIndividual(secondGenotype);

  ASSERT_TRUE(firstIndividual != secondIndividual);
}
