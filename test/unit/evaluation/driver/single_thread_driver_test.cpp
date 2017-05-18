#include "gram/evaluation/driver/SingleThreadDriver.h"

#include <catch.hpp>
#include <fakeit.hpp>

#include <memory>

#include "gram/evaluation/Evaluator.h"
#include "gram/individual/Fitness.h"
#include "gram/individual/Genotype.h"
#include "gram/individual/Individual.h"
#include "gram/population/Individuals.h"
#include "gram/population/Population.h"
#include <gram/population/reproducer/PassionateReproducer.h>

using namespace fakeit;
using namespace gram;
using namespace std;

TEST_CASE("single thread driver evaluates all individuals in a population", "[single_thread_driver]") {
  Mock<Mapper> mapperMock;
  Fake(Dtor(mapperMock));
  When(Method(mapperMock, map).Using(Genotype({0, 0, 0}))).Return(Phenotype("zero"));
  When(Method(mapperMock, map).Using(Genotype({1, 1, 1}))).Return(Phenotype("one"));
  When(Method(mapperMock, map).Using(Genotype({2, 2, 2}))).Return(Phenotype("two"));
  auto mapper = unique_ptr<Mapper>(&mapperMock.get());

  Mock<Evaluator> evaluatorMock;
  Fake(Dtor(evaluatorMock));
  When(Method(evaluatorMock, evaluate).Using(Phenotype("zero"))).Return(Fitness(0.0));
  When(Method(evaluatorMock, evaluate).Using(Phenotype("one"))).Return(Fitness(1.0));
  When(Method(evaluatorMock, evaluate).Using(Phenotype("two"))).Return(Fitness(2.0));
  auto evaluator = unique_ptr<Evaluator>(&evaluatorMock.get());

  Individual individual1(Genotype({0, 0, 0}));
  Individual individual2(Genotype({1, 1, 1}));
  Individual individual3(Genotype({2, 2, 2}));

  Individuals individuals({individual1, individual2, individual3});

  SingleThreadDriver driver(move(mapper), move(evaluator));

  driver.evaluate(individuals);

  REQUIRE(individuals[0].hasFitnessCalculated());
  REQUIRE(individuals[1].hasFitnessCalculated());
  REQUIRE(individuals[2].hasFitnessCalculated());
}
