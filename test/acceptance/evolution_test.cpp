#include <gtest/gtest.h>
#include <gtest/fakeit.hpp>

#include <gram/Evolution.h>
#include <gram/util/number_generator/TwisterNumberGenerator.h>
#include <gram/population/selector/TournamentSelector.h>
#include <gram/util/bool_generator/TwisterBoolGenerator.h>
#include <gram/population/initializer/RandomInitializer.h>
#include <gram/language/parser/BnfRuleParser.h>

using namespace gram::evolution;
using namespace gram::individual;
using namespace gram::population;
using namespace gram::language;
using namespace gram::util;

using namespace fakeit;

TEST(evolution_test, test_something) {
  unsigned long max = std::numeric_limits<unsigned long>::max();

  std::unique_ptr<NumberGenerator> numberGenerator1 = std::make_unique<TwisterNumberGenerator>(max);
  std::unique_ptr<NumberGenerator> numberGenerator2 = std::make_unique<TwisterNumberGenerator>(29);
  std::unique_ptr<NumberGenerator> numberGenerator3 = std::make_unique<TwisterNumberGenerator>(11);
  std::unique_ptr<NumberGenerator> numberGenerator4 = std::make_unique<TwisterNumberGenerator>(11);
  std::unique_ptr<BoolGenerator> boolGenerator = std::make_unique<TwisterBoolGenerator>(0.1);

  TournamentSelector selector(std::move(numberGenerator1));
  Mutation mutation(std::move(boolGenerator), std::move(numberGenerator2));
  Crossover crossover(std::move(numberGenerator3));
  auto generator = std::make_shared<Generator>(selector, crossover, mutation);

  std::string grammarString =
      "<number> ::= <number> <digit> | <digit>\n"
      "<digit> ::= \"0\" | \"1\" | \"2\" | \"3\" | \"4\" | \"5\" | \"6\" | \"7\" | \"8\" | \"9\"";

  BnfRuleParser parser;

  std::shared_ptr<Grammar> grammar = parser.parse(grammarString);

  Mapper mapper(grammar);
  auto language = std::make_shared<Language>(grammar, mapper);

  RandomInitializer initializer(std::move(numberGenerator4), language, 16);

  Mock<Evaluator> evaluator;
  When(Method(evaluator, evaluate)).AlwaysDo([](auto program) {
    unsigned long length = program.length();

    return (length == 0 || length > 9) ? 0 : std::stoi(program);
  });

  Mock<FitnessCalculator> calculator;
  When(Method(calculator, calculate)).AlwaysDo([](auto desired, auto actual) {
    return std::abs(desired - actual);
  });

  auto processor = std::make_shared<Processor>(evaluator.get(), calculator.get());

  Evolution evolution(processor);

  Population population = initializer.initialize(1000, generator);

  Individual result = evolution.run(population, 1470);

  double fitness = result.fitness();

  ASSERT_NEAR(0.0, fitness, 0.001);
}
