#include <gtest/gtest.h>

#include <gram/evolution/operator/Crossover.h>
#include <gram/fake/util/FakeNumberGenerator.h>

using namespace gram::evolution;
using namespace gram::population::individual;
using namespace gram::fake::util;

TEST(crossover_operator_test, test_it_combines_genotypes_with_the_same_length) {
  Genotype firstGenotype{0, 1, 2, 3, 4};
  Genotype secondGenotype{5, 6, 7, 8, 9};
  Genotype expectedGenotype{0, 1, 7, 8, 9};

  FakeNumberGenerator numberGenerator{2};

  Crossover crossover(numberGenerator);
  Genotype combinedGenotype = crossover.apply(firstGenotype, secondGenotype);

  ASSERT_EQ(expectedGenotype, combinedGenotype);
}

TEST(crossover_operator_test, test_it_combines_short_and_long_genotypes) {
  Genotype firstGenotype{0, 1, 2};
  Genotype secondGenotype{5, 6, 7, 8, 9};
  Genotype expectedGenotype{0, 1, 7, 8, 9};

  FakeNumberGenerator numberGenerator{2};

  Crossover crossover(numberGenerator);
  Genotype combinedGenotype = crossover.apply(firstGenotype, secondGenotype);

  ASSERT_EQ(expectedGenotype, combinedGenotype);
}

TEST(crossover_operator_test, test_it_combines_long_and_short_genotypes) {
  Genotype firstGenotype{0, 1, 2, 3, 4};
  Genotype secondGenotype{5, 6};
  Genotype expectedGenotype{0, 1};

  FakeNumberGenerator numberGenerator{2};

  Crossover crossover(numberGenerator);
  Genotype combinedGenotype = crossover.apply(firstGenotype, secondGenotype);

  ASSERT_EQ(expectedGenotype, combinedGenotype);
}
