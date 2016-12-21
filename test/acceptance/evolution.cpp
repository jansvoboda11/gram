#include <gmock/gmock.h>

#include <gram/Evolution.h>
#include <gram/evolution/selector/TournamentSelector.h>
#include <gram/util/number_generator/TwisterNumberGenerator.h>
#include <gram/util/bool_generator/TwisterBoolGenerator.h>
#include <gram/population/initializer/RandomInitializer.h>
#include <gram/evolution/fitness_calculator/ParabolaFitnessCalculator.h>

using namespace gram::evolution;
using namespace gram::individual;
using namespace gram::population;
using namespace gram::language;
using namespace gram::util;
using namespace gram::grammar;

using ::testing::NiceMock;
using ::testing::Return;
using ::testing::_;

class FakeEvaluator : public Evaluator {
  int evaluate(std::shared_ptr<gram::individual::Individual> individual) {
    std::string serialized = individual->serialize();

    unsigned long length = serialized.length();

    if (length == 0 || length > 9) {
      return 0;
    }

    return std::stoi(serialized);
  };
};

class FakeFitnessCalculator : public FitnessCalculator {
 public:
  double calculate(int desired, int actual) {
    return std::abs(123 - actual);
  };
};

TEST(evolution_test, test_something) {
  TwisterNumberGenerator numberGenerator(29);
  TournamentSelector selector(numberGenerator);
  Crossover crossover(numberGenerator);
  TwisterBoolGenerator boolGenerator(0.1);
  Mutation mutation(boolGenerator, numberGenerator);
  Generator generator(selector, crossover, mutation);

  RandomInitializer initializer(numberGenerator, 16);

  Terminal digit0("0");
  Terminal digit1("1");
  Terminal digit2("2");
  Terminal digit3("3");
  Terminal digit4("4");
  Terminal digit5("5");
  Terminal digit6("6");
  Terminal digit7("7");
  Terminal digit8("8");
  Terminal digit9("9");

  auto option0 = std::make_shared<Option>();
  auto option1 = std::make_shared<Option>();
  auto option2 = std::make_shared<Option>();
  auto option3 = std::make_shared<Option>();
  auto option4 = std::make_shared<Option>();
  auto option5 = std::make_shared<Option>();
  auto option6 = std::make_shared<Option>();
  auto option7 = std::make_shared<Option>();
  auto option8 = std::make_shared<Option>();
  auto option9 = std::make_shared<Option>();

  option0->addTerminal(digit0);
  option1->addTerminal(digit1);
  option2->addTerminal(digit2);
  option3->addTerminal(digit3);
  option4->addTerminal(digit4);
  option5->addTerminal(digit5);
  option6->addTerminal(digit6);
  option7->addTerminal(digit7);
  option8->addTerminal(digit8);
  option9->addTerminal(digit9);

  auto digit = std::make_shared<NonTerminal>();
//  digit->addOption(option0);
  digit->addOption(option1);
  digit->addOption(option2);
  digit->addOption(option3);
//  digit->addOption(option4);
//  digit->addOption(option5);
//  digit->addOption(option6);
//  digit->addOption(option7);
//  digit->addOption(option8);
//  digit->addOption(option9);

  auto startSymbol = std::make_shared<NonTerminal>();

  auto digitOption = std::make_shared<Option>();
  digitOption->addNonTerminal(digit);

  auto numberOption = std::make_shared<Option>();
  numberOption->addNonTerminal(digit);
  numberOption->addNonTerminal(startSymbol);

  startSymbol->addOption(digitOption);
  startSymbol->addOption(numberOption);

  Grammar grammar(startSymbol);
  Mapper mapper(grammar);
  FakeEvaluator evaluator;
  FakeFitnessCalculator calculator;
  Processor processor(mapper, evaluator, calculator);

  Evolution evolution;
  evolution.setGenerator(&generator);
  evolution.setInitializer(&initializer);
  evolution.setProcessor(&processor);

  Individual result = evolution.run(50, 100);

  double fitness = result.getFitness();

  ASSERT_NEAR(0.0, fitness, 0.001);
}
