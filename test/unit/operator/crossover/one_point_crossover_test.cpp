#include "gram/operator/crossover/OnePointCrossover.h"

#include <catch.hpp>
#include <fakeit.hpp>

using namespace fakeit;
using namespace gram;
using namespace std;

TEST_CASE("genotypes of the same length can be combined", "[one_point_crossover]") {
  Mock<NumberGenerator> mock;
  Fake(Dtor(mock));
  When(Method(mock, generate)).Return(2);
  auto numberGenerator = unique_ptr<NumberGenerator>(&mock.get());

  OnePointCrossover crossover(move(numberGenerator));

  Genotype genotype1({0, 1, 2, 3, 4});
  Genotype genotype2({5, 6, 7, 8, 9});

  REQUIRE(Genotype({0, 1, 7, 8, 9}) == crossover.apply(genotype1, genotype2));
}

TEST_CASE("short and long genotypes can be combined", "[one_point_crossover]") {
  Mock<NumberGenerator> mock;
  Fake(Dtor(mock));
  When(Method(mock, generate)).Return(2);
  auto numberGenerator = unique_ptr<NumberGenerator>(&mock.get());

  OnePointCrossover crossover(move(numberGenerator));

  Genotype genotype1({0, 1, 2});
  Genotype genotype2({5, 6, 7, 8, 9});

  REQUIRE(Genotype({0, 1, 7, 8, 9}) == crossover.apply(genotype1, genotype2));
}

TEST_CASE("long and short genotypes can be combined", "[one_point_crossover]") {
  Mock<NumberGenerator> mock;
  Fake(Dtor(mock));
  When(Method(mock, generate)).Return(2);
  auto numberGenerator = unique_ptr<NumberGenerator>(&mock.get());

  OnePointCrossover crossover(move(numberGenerator));

  Genotype genotype1({5, 6, 7, 8, 9});
  Genotype genotype2({0, 1, 2});

  REQUIRE(Genotype({5, 6, 2}) == crossover.apply(genotype1, genotype2));
}
