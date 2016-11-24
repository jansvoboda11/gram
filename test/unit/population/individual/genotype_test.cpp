#include <gtest/gtest.h>

#include <population/individual/Genotype.h>

using namespace gram::population::individual;

TEST(genotype_test, test_it_creates_object_with_integer_vector) {
  std::vector<int> numbers{1, 2, 3};

  Genotype genotype(numbers);

  ASSERT_EQ(1, genotype.geneAt(0));
  ASSERT_EQ(2, genotype.geneAt(1));
  ASSERT_EQ(3, genotype.geneAt(2));
}
