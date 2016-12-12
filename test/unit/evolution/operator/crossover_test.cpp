#include <gtest/gtest.h>

#include <gram/evolution/operator/Crossover.h>
#include <gram/util/number_generator/NumberGeneratorMock.h>

using namespace gram::evolution;
using namespace gram::individual;
using namespace gram::util;

using ::testing::NiceMock;
using ::testing::Return;

TEST(crossover_operator_test, test_it_combines_genotypes_with_the_same_length) {
  Genotype genotype1{0, 1, 2, 3, 4};
  Genotype genotype2{5, 6, 7, 8, 9};

  NiceMock<NumberGeneratorMock> numberGenerator;
  ON_CALL(numberGenerator, generate())
      .WillByDefault(Return(2));

  Crossover crossover(numberGenerator);

  Genotype combinedGenotype = crossover.apply(genotype1, genotype2);

  Genotype expectedGenotype{0, 1, 7, 8, 9};
  ASSERT_EQ(expectedGenotype, combinedGenotype);
}

TEST(crossover_operator_test, test_it_combines_short_and_long_genotypes) {
  Genotype genotype1{0, 1, 2};
  Genotype genotype2{5, 6, 7, 8, 9};

  NiceMock<NumberGeneratorMock> numberGenerator;
  ON_CALL(numberGenerator, generate())
      .WillByDefault(Return(2));

  Crossover crossover(numberGenerator);

  Genotype combinedGenotype = crossover.apply(genotype1, genotype2);

  Genotype expectedGenotype{0, 1, 7, 8, 9};
  ASSERT_EQ(expectedGenotype, combinedGenotype);
}

TEST(crossover_operator_test, test_it_combines_long_and_short_genotypes) {
  Genotype genotype1{0, 1, 2, 3, 4};
  Genotype genotype2{5, 6};

  NiceMock<NumberGeneratorMock> numberGenerator;
  ON_CALL(numberGenerator, generate())
      .WillByDefault(Return(2));

  Crossover crossover(numberGenerator);

  Genotype combinedGenotype = crossover.apply(genotype1, genotype2);

  Genotype expectedGenotype{0, 1};
  ASSERT_EQ(expectedGenotype, combinedGenotype);
}
