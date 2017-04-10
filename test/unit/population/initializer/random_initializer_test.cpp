#include <catch.hpp>
#include <fakeit.hpp>

#include <gram/population/initializer/RandomInitializer.h>

using namespace fakeit;
using namespace gram;
using namespace std;

TEST_CASE("random initializer initializes new population", "[random_initializer]") {
  Genotype genotype1({0, 1, 2});
  Genotype genotype2({3, 0, 1});
  Genotype genotype3({2, 3, 0});

  Individual individual1(genotype1);
  Individual individual2(genotype2);
  Individual individual3(genotype3);

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

  RandomInitializer initializer(move(numberGenerator), 3);

  Population population = initializer.initialize(3, reproducer);

  REQUIRE(population.number() == 0);
  REQUIRE(population.size() == 3);
  REQUIRE(population[0] == individual1);
  REQUIRE(population[1] == individual2);
  REQUIRE(population[2] == individual3);
}
