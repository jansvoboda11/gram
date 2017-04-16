#include <catch.hpp>
#include <fakeit.hpp>

#include <gram/evaluation/driver/SingleThreadDriver.h>
#include <gram/individual/crossover/OnePointCrossover.h>
#include <gram/individual/mutation/FastCodonMutation.h>
#include <gram/language/parser/BnfRuleParser.h>
#include <gram/language/mapper/ContextFreeMapper.h>
#include <gram/population/initializer/RandomInitializer.h>
#include <gram/population/reproducer/PassionateReproducer.h>
#include <gram/population/selector/TournamentSelector.h>
#include <gram/random/number_generator/XorShiftNumberGenerator.h>
#include <gram/util/logger/NullLogger.h>
#include <gram/Evolution.h>

#include "StringDiffEvaluator.h"

using namespace fakeit;
using namespace gram;
using namespace std;

TEST_CASE("evolution_test") {
  auto numberGenerator1 = make_unique<XorShiftNumberGenerator>();
  auto numberGenerator2 = make_unique<XorShiftNumberGenerator>();
  auto numberGenerator3 = make_unique<XorShiftNumberGenerator>();
  auto numberGenerator4 = make_unique<XorShiftNumberGenerator>();
  auto numberGenerator5 = make_unique<XorShiftNumberGenerator>();
  auto stepGenerator = make_unique<BernoulliDistributionStepGenerator>(0.1, move(numberGenerator5));

  auto selector = make_unique<TournamentSelector>(20, move(numberGenerator1));
  auto mutation = make_unique<FastCodonMutation>(move(stepGenerator), move(numberGenerator2));
  auto crossover = make_unique<OnePointCrossover>(move(numberGenerator3));
  auto reproducer = make_shared<PassionateReproducer>(move(selector), move(crossover), move(mutation));

  string grammarString =
      "<word> ::= <word> <char> | <char>\n"
      "<char> ::= \"g\" | \"r\" | \"a\" | \"m\"";

  BnfRuleParser parser;

  auto grammar = make_shared<ContextFreeGrammar>(parser.parse(grammarString));
  auto mapper = make_shared<ContextFreeMapper>(grammar, 1);

  RandomInitializer initializer(move(numberGenerator4), 50);

  auto evaluator = make_unique<StringDiffEvaluator>(mapper, "gram");
  auto evaluationDriver = make_unique<SingleThreadDriver>(move(evaluator));
  auto logger = make_unique<NullLogger>();

  Evolution evolution(move(evaluationDriver), move(logger));

  Population population = initializer.initialize(200, reproducer);

  function<bool(Population&)> successCondition = [](Population& currentPopulation) -> bool {
    return currentPopulation.bestFitness() == 0;
  };

  Individual result = evolution.run(population, successCondition);

  REQUIRE(result.fitness() == 0.0);
  REQUIRE(result.serialize(*mapper) == "gram");
}
