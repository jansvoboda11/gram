#include <gtest/gtest.h>
#include <gtest/fakeit.hpp>

#include <gram/language/parser/BnfRuleParser.h>
#include <gram/population/initializer/RandomInitializer.h>
#include <gram/population/selector/TournamentSelector.h>
#include <gram/util/bool_generator/TwisterBoolGenerator.h>
#include <gram/util/number_generator/TwisterNumberGenerator.h>
#include <gram/Evolution.h>

using namespace fakeit;
using namespace gram;
using namespace std;

TEST(evolution_test, test_something) {
  unsigned long max = numeric_limits<unsigned long>::max();

  unique_ptr<NumberGenerator> numberGenerator1 = make_unique<TwisterNumberGenerator>(max);
  unique_ptr<NumberGenerator> numberGenerator2 = make_unique<TwisterNumberGenerator>(29);
  unique_ptr<NumberGenerator> numberGenerator3 = make_unique<TwisterNumberGenerator>(11);
  unique_ptr<NumberGenerator> numberGenerator4 = make_unique<TwisterNumberGenerator>(11);
  unique_ptr<BoolGenerator> boolGenerator = make_unique<TwisterBoolGenerator>(0.1);

  TournamentSelector selector(move(numberGenerator1));
  Mutation mutation(move(boolGenerator), move(numberGenerator2));
  Crossover crossover(move(numberGenerator3));
  auto generator = make_shared<Generator>(selector, crossover, mutation);

  string grammarString =
      "<number> ::= <number> <digit> | <digit>\n"
          "<digit> ::= \"0\" | \"1\" | \"2\" | \"3\" | \"4\" | \"5\" | \"6\" | \"7\" | \"8\" | \"9\"";

  BnfRuleParser parser;

  shared_ptr<Grammar> grammar = parser.parse(grammarString);

  Mapper mapper(grammar);
  auto language = make_shared<Language>(grammar, mapper);

  RandomInitializer initializer(move(numberGenerator4), language, 16);

  Mock<Evaluator> evaluator;
  When(Method(evaluator, evaluate)).AlwaysDo([](auto program) {
    unsigned long length = program.length();

    return (length == 0 || length > 9) ? 0 : stoi(program);
  });

  Mock<FitnessCalculator> calculator;
  When(Method(calculator, calculate)).AlwaysDo([](auto desired, auto actual) {
    return abs(desired - actual);
  });

  auto processor = make_unique<Processor>(evaluator.get(), calculator.get());

  Evolution evolution(move(processor));

  Population population = initializer.initialize(1000, generator);

  Individual result = evolution.run(population, 1470);

  double fitness = result.fitness();

  ASSERT_NEAR(0.0, fitness, 0.001);
}
