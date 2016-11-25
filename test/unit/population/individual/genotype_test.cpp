#include <gtest/gtest.h>

#include <population/individual/Genotype.h>

using namespace gram::population::individual;

TEST(genotype_test, test_it_creates_object_with_integer_vector) {
  std::vector<int> numbers{1, 2, 3};

  Genotype genotype(numbers);

  ASSERT_EQ(1, genotype[0]);
  ASSERT_EQ(2, genotype[1]);
  ASSERT_EQ(3, genotype[2]);
}

TEST(genotype_test, test_it_recognizes_two_same_objects) {
  std::vector<int> firstNumbers{1, 2, 3};
  std::vector<int> secondNumbers{1, 2, 3};

  Genotype firstGenotype(firstNumbers);
  Genotype secondGenotype(secondNumbers);

  ASSERT_TRUE(firstGenotype == secondGenotype);
}

TEST(genotype_test, test_it_recognizes_two_different_objects) {
  std::vector<int> firstNumbers{1, 2, 3};
  std::vector<int> secondNumbers{3, 2, 1};

  Genotype firstGenotype(firstNumbers);
  Genotype secondGenotype(secondNumbers);

  ASSERT_TRUE(firstGenotype != secondGenotype);
}
