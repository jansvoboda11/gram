#include <gtest/gtest.h>
#include <gtest/fakeit.hpp>

#include <gram/Evolution.h>
#include <gram/util/number_generator/TwisterNumberGenerator.h>
#include <gram/population/selector/TournamentSelector.h>
#include <gram/util/bool_generator/TwisterBoolGenerator.h>
#include <gram/population/initializer/RandomInitializer.h>

using namespace gram::evolution;
using namespace gram::individual;
using namespace gram::population;
using namespace gram::language;
using namespace gram::util;

class FakeEvaluator : public Evaluator {
  int evaluate(std::string program) {
    unsigned long length = program.length();

    if (length == 0 || length > 9) {
      return 0;
    }

    return std::stoi(program);
  }
};

class FakeFitnessCalculator : public FitnessCalculator {
 public:
  double calculate(int desired, int actual) {
    return std::abs(desired - actual);
  }
};

TEST(evolution_test, test_something) {
  std::unique_ptr<NumberGenerator> numberGenerator1 = std::make_unique<TwisterNumberGenerator>(std::numeric_limits<unsigned long>::max());
  std::unique_ptr<NumberGenerator> numberGenerator2 = std::make_unique<TwisterNumberGenerator>(29);
  std::unique_ptr<NumberGenerator> numberGenerator3 = std::make_unique<TwisterNumberGenerator>(11);
  std::unique_ptr<NumberGenerator> numberGenerator4 = std::make_unique<TwisterNumberGenerator>(11);
  std::unique_ptr<BoolGenerator> boolGenerator = std::make_unique<TwisterBoolGenerator>(0.1);

  TournamentSelector selector(std::move(numberGenerator1));
  Mutation mutation(std::move(boolGenerator), std::move(numberGenerator2));
  Crossover crossover(std::move(numberGenerator3));
  auto generator = std::make_shared<Generator>(selector, crossover, mutation);

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
  digit->addOption(option0);
  digit->addOption(option1);
  digit->addOption(option2);
  digit->addOption(option3);
  digit->addOption(option4);
  digit->addOption(option5);
  digit->addOption(option6);
  digit->addOption(option7);
  digit->addOption(option8);
  digit->addOption(option9);

  auto startSymbol = std::make_shared<NonTerminal>();

  auto digitOption = std::make_shared<Option>();
  digitOption->addNonTerminal(digit);

  auto numberOption = std::make_shared<Option>();
  numberOption->addNonTerminal(digit);
  numberOption->addNonTerminal(startSymbol);

  startSymbol->addOption(digitOption);
  startSymbol->addOption(numberOption);

  auto grammar = std::make_shared<Grammar>();
  grammar->addRule("start", startSymbol);
  grammar->addRule("digit", digit);

  Mapper mapper(grammar);
  auto language = std::make_shared<Language>(grammar, mapper);

  RandomInitializer initializer(std::move(numberGenerator4), language, 16);

  FakeEvaluator evaluator;
  FakeFitnessCalculator calculator;
  auto processor = std::make_shared<Processor>(evaluator, calculator);

  Evolution evolution(processor);

  Population population = initializer.initialize(1000, generator);

  Individual result = evolution.run(population, 1470);

  double fitness = result.fitness();

  ASSERT_NEAR(0.0, fitness, 0.001);
}
