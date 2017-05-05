#include "gram/evaluation/driver/SingleThreadDriver.h"

#include <catch.hpp>
#include <fakeit.hpp>

#include <memory>

#include "gram/evaluation/Evaluator.h"
#include "gram/individual/Genotype.h"
#include "gram/individual/Individual.h"
#include "gram/population/Individuals.h"
#include "gram/population/Population.h"
#include <gram/population/reproducer/PassionateReproducer.h>

using namespace fakeit;
using namespace gram;
using namespace std;

TEST_CASE("single thread driver evaluates all individuals in a population", "[single_thread_driver]") {
  Mock<Evaluator> evaluatorMock;
  Fake(Dtor(evaluatorMock));
  When(Method(evaluatorMock, evaluate)).Return(1).Return(2).Return(3);
  auto evaluator = unique_ptr<Evaluator>(&evaluatorMock.get());

  Mock<Reproducer> reproducerMock;
  Fake(Dtor(reproducerMock));
  auto reproducer = unique_ptr<Reproducer>(&reproducerMock.get());

  Genotype genotype1({0, 0, 0});
  Genotype genotype2({1, 1, 1});
  Genotype genotype3({2, 2, 2});

  Individual individual1(genotype1);
  Individual individual2(genotype2);
  Individual individual3(genotype3);

  Individuals individuals;

  individuals.addIndividual(individual1);
  individuals.addIndividual(individual2);
  individuals.addIndividual(individual3);

  Population population(individuals, move(reproducer), 0);

  SingleThreadDriver driver(move(evaluator));

  driver.evaluate(population);

  REQUIRE(population[0].hasFitnessCalculated());
  REQUIRE(population[1].hasFitnessCalculated());
  REQUIRE(population[2].hasFitnessCalculated());
}
