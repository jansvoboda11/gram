#include <gmock/gmock.h>

#include <gram/evolution/Evolution.h>
#include <gram/evolution/selector/TournamentSelector.h>
#include <gram/util/number_generator/TwisterNumberGenerator.h>
#include <gram/util/bool_generator/TwisterBoolGenerator.h>
#include <gram/population/initializer/RandomInitializer.h>
#include <gram/evolution/fitness_calculator/ParabolaFitnessCalculator.h>
#include <gram/language/EvaluatorMock.h>

using namespace gram::evolution;
using namespace gram::individual;
using namespace gram::population;
using namespace gram::language;
using namespace gram::util;
using namespace gram::grammar;

using ::testing::NiceMock;
using ::testing::Return;
using ::testing::_;

TEST(evolution_test, test_something) {
  TwisterNumberGenerator numberGenerator(30);
  TournamentSelector selector(numberGenerator);
  Crossover crossover(numberGenerator);
  TwisterBoolGenerator boolGenerator(0.01);
  Mutation mutation(boolGenerator, numberGenerator);
  Generator generator(selector, crossover, mutation);

  RandomInitializer initializer(numberGenerator, 10);

  auto startSymbol = std::make_shared<NonTerminal>();
  auto option = std::make_shared<Option>();
  Terminal terminal("");
  option->addTerminal(terminal);
  startSymbol->addOption(option);

  Grammar grammar(startSymbol);
  Mapper mapper(grammar);
  NiceMock<EvaluatorMock> evaluator;
  ON_CALL(evaluator, evaluate(_))
      .WillByDefault(Return(4));
  ParabolaFitnessCalculator calculator(10.0);
  Processor processor(mapper, evaluator, calculator);

  Evolution evolution;
  evolution.setGenerator(&generator);
  evolution.setInitializer(&initializer);
  evolution.setProcessor(&processor);

  Individual result = evolution.run(20, 1);

  Genotype genotype = result.getGenotype();
}
