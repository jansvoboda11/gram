#include "gram/evaluation/driver/MultiThreadDriver.h"

#include <catch.hpp>
#include <fakeit.hpp>

#include <memory>

#include "gram/evaluation/Evaluator.h"
#include "gram/individual/Genotype.h"
#include "gram/individual/Individual.h"
#include "gram/population/Individuals.h"
#include <gram/population/reproducer/PassionateReproducer.h>
#include "gram/population/Population.h"

using namespace fakeit;
using namespace gram;
using namespace std;

TEST_CASE("multi thread driver evaluates all individuals in a population", "[single_thread_driver]") {
  Mock<Evaluator> evaluatorMock1;
  Fake(Dtor(evaluatorMock1));
  When(Method(evaluatorMock1, evaluate)).Return(1);
  auto evaluator1 = unique_ptr<Evaluator>(&evaluatorMock1.get());

  Mock<Evaluator> evaluatorMock2;
  Fake(Dtor(evaluatorMock2));
  When(Method(evaluatorMock2, evaluate)).Return(2);
  auto evaluator2 = unique_ptr<Evaluator>(&evaluatorMock2.get());

  Mock<Evaluator> evaluatorMock3;
  Fake(Dtor(evaluatorMock3));
  When(Method(evaluatorMock3, evaluate)).Return(3);
  auto evaluator3 = unique_ptr<Evaluator>(&evaluatorMock3.get());

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

  vector<unique_ptr<Evaluator>> evaluators;
  evaluators.push_back(move(evaluator1));
  evaluators.push_back(move(evaluator2));
  evaluators.push_back(move(evaluator3));

  MultiThreadDriver driver(move(evaluators));

  driver.evaluate(population);

  REQUIRE(population[0].hasFitnessCalculated());
  REQUIRE(population[1].hasFitnessCalculated());
  REQUIRE(population[2].hasFitnessCalculated());
}

TEST_CASE("multi thread driver evaluates all individuals with distinct drivers", "[single_thread_driver]") {
  Mock<Evaluator> evaluatorMock1;
  Fake(Dtor(evaluatorMock1));
  When(Method(evaluatorMock1, evaluate)).AlwaysReturn(1);
  auto evaluator1 = unique_ptr<Evaluator>(&evaluatorMock1.get());

  Mock<Evaluator> evaluatorMock2;
  Fake(Dtor(evaluatorMock2));
  When(Method(evaluatorMock2, evaluate)).AlwaysReturn(2);
  auto evaluator2 = unique_ptr<Evaluator>(&evaluatorMock2.get());

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

  vector<unique_ptr<Evaluator>> evaluators;
  evaluators.push_back(move(evaluator1));
  evaluators.push_back(move(evaluator2));

  MultiThreadDriver driver(move(evaluators));

  driver.evaluate(population);

  Verify(Method(evaluatorMock1, evaluate)).AtLeastOnce();
  Verify(Method(evaluatorMock2, evaluate)).AtLeastOnce();

  REQUIRE(population[0].hasFitnessCalculated());
  REQUIRE(population[1].hasFitnessCalculated());
  REQUIRE(population[2].hasFitnessCalculated());
}
