#include "gram/evaluation/EvaluatorCache.h"

#include <catch.hpp>
#include <fakeit.hpp>

#include <memory>

#include "gram/evaluation/Evaluator.h"
#include "gram/individual/Fitness.h"
#include "gram/individual/Phenotype.h"

using namespace fakeit;
using namespace gram;
using namespace std;

TEST_CASE("caching evaluator calls the real one only once", "[caching_evaluator]") {
  Mock<Evaluator> evaluatorMock;
  Fake(Dtor(evaluatorMock));
  When(Method(evaluatorMock, evaluate)).AlwaysReturn(0.0);
  auto evaluator = unique_ptr<Evaluator>(&evaluatorMock.get());

  EvaluatorCache cachingEvaluator(move(evaluator));

  double fitness1 = cachingEvaluator.evaluate(Phenotype("example"));
  double fitness2 = cachingEvaluator.evaluate(Phenotype("example"));

  Verify(Method(evaluatorMock, evaluate)).Exactly(Once);

  REQUIRE(fitness1 == Fitness(0.0));
  REQUIRE(fitness2 == Fitness(0.0));
}
