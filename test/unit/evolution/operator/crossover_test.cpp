#include <gtest/gtest.h>

#include <evolution/operator/Crossover.h>
#include <util/FakeNumberGenerator.h>

using namespace gram::evolution;
using namespace gram::population::individual;
using namespace gram::fake::util;

TEST(crossover_operator_test, test_it_combines_genotypes_with_the_same_length) {
  std::vector<int> firstGenes{0, 1, 2, 3, 4};
  std::vector<int> secondGenes{5, 6, 7, 8, 9};
  std::vector<int> expectedGenes{0, 1, 7, 8, 9};

  Genotype firstGenotype(firstGenes);
  Genotype secondGenotype(secondGenes);
  Genotype expectedGenotype(expectedGenes);

  FakeNumberGenerator numberGenerator;

  Crossover crossover(numberGenerator);
  Genotype combinedGenotype = crossover.apply(firstGenotype, secondGenotype);

  ASSERT_EQ(expectedGenotype, combinedGenotype);
}

TEST(crossover_operator_test, test_it_combines_short_and_long_genotypes) {
  std::vector<int> firstGenes{0, 1, 2};
  std::vector<int> secondGenes{5, 6, 7, 8, 9};
  std::vector<int> expectedGenes{0, 1, 7, 8, 9};

  Genotype firstGenotype(firstGenes);
  Genotype secondGenotype(secondGenes);
  Genotype expectedGenotype(expectedGenes);

  FakeNumberGenerator numberGenerator;

  Crossover crossover(numberGenerator);
  Genotype combinedGenotype = crossover.apply(firstGenotype, secondGenotype);

  ASSERT_EQ(expectedGenotype, combinedGenotype);
}

TEST(crossover_operator_test, test_it_combines_long_and_short_genotypes) {
  std::vector<int> firstGenes{0, 1, 2, 3, 4};
  std::vector<int> secondGenes{5, 6};
  std::vector<int> expectedGenes{0, 1};

  Genotype firstGenotype(firstGenes);
  Genotype secondGenotype(secondGenes);
  Genotype expectedGenotype(expectedGenes);

  FakeNumberGenerator numberGenerator;

  Crossover crossover(numberGenerator);
  Genotype combinedGenotype = crossover.apply(firstGenotype, secondGenotype);

  ASSERT_EQ(expectedGenotype, combinedGenotype);
}
