#include <gtest/gtest.h>

#include <gram/individual/operator/Crossover.h>
#include <gram/util/number_generator/TwisterNumberGenerator.h>

#include "../../../lib/fakeit/fakeit.hpp"

using namespace gram::individual;
using namespace gram::util;

using namespace fakeit;

TEST(crossover_operator_test, test_it_combines_genotypes_of_the_same_length) {
  Genotype genotype1{0, 1, 2, 3, 4};
  Genotype genotype2{5, 6, 7, 8, 9};

  Mock<NumberGenerator> mock;
  Fake(Dtor(mock));
  When(Method(mock,generate)).Return(2);

  auto numberGenerator = std::unique_ptr<NumberGenerator>(&mock.get());

  Crossover crossover(std::move(numberGenerator));

  Genotype combinedGenotype = crossover.apply(genotype1, genotype2);

  Genotype expectedGenotype{0, 1, 7, 8, 9};
  ASSERT_EQ(expectedGenotype, combinedGenotype);
}

TEST(crossover_operator_test, test_it_combines_short_and_long_genotypes) {
  Genotype genotype1{0, 1, 2};
  Genotype genotype2{5, 6, 7, 8, 9};

  Mock<NumberGenerator> mock;
  Fake(Dtor(mock));
  When(Method(mock,generate)).Return(2);

  auto numberGenerator = std::unique_ptr<NumberGenerator>(&mock.get());

  Crossover crossover(std::move(numberGenerator));

  Genotype combinedGenotype = crossover.apply(genotype1, genotype2);

  Genotype expectedGenotype{0, 1, 7, 8, 9};
  ASSERT_EQ(expectedGenotype, combinedGenotype);
}

TEST(crossover_operator_test, test_it_combines_long_and_short_genotypes) {
  Genotype genotype1{0, 1, 2, 3, 4};
  Genotype genotype2{5, 6};

  Mock<NumberGenerator> mock;
  Fake(Dtor(mock));
  When(Method(mock,generate)).Return(2);

  auto numberGenerator = std::unique_ptr<NumberGenerator>(&mock.get());

  Crossover crossover(std::move(numberGenerator));

  Genotype combinedGenotype = crossover.apply(genotype1, genotype2);

  Genotype expectedGenotype{0, 1};
  ASSERT_EQ(expectedGenotype, combinedGenotype);
}
