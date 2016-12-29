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

class FakeEvaluator : public Evaluator {
  int evaluate(std::string program) const {
    unsigned long length = program.length();

    return (length == 0 || length > 9) ? 0 : stoi(program);
  };
};

class FakeFitnessCalculator : public FitnessCalculator {
  double calculate(int desired, int actual) const {
    return abs(desired - actual);
  };
};

TEST(evolution_test, test_something) {
  unsigned long max = numeric_limits<unsigned long>::max();

  unique_ptr<NumberGenerator> numberGenerator1 = make_unique<TwisterNumberGenerator>(max);
  unique_ptr<NumberGenerator> numberGenerator2 = make_unique<TwisterNumberGenerator>(29);
  unique_ptr<NumberGenerator> numberGenerator3 = make_unique<TwisterNumberGenerator>(11);
  unique_ptr<NumberGenerator> numberGenerator4 = make_unique<TwisterNumberGenerator>(11);
  unique_ptr<BoolGenerator> boolGenerator = make_unique<TwisterBoolGenerator>(0.1);

  auto selector = make_unique<TournamentSelector>(move(numberGenerator1));
  auto mutation = make_unique<Mutation>(move(boolGenerator), move(numberGenerator2));
  auto crossover = make_unique<Crossover>(move(numberGenerator3));
  auto reproducer = make_shared<Reproducer>(move(selector), move(crossover), move(mutation));

  string grammarString =
      "<number> ::= <number> <digit> | <digit>\n"
          "<digit> ::= \"0\" | \"1\" | \"2\" | \"3\" | \"4\" | \"5\" | \"6\" | \"7\" | \"8\" | \"9\"";

  BnfRuleParser parser;

  auto grammar = make_shared<Grammar>(parser.parse(grammarString));
  auto mapper = make_unique<Mapper>(grammar);
  auto language = make_shared<Language>(grammar, move(mapper));

  RandomInitializer initializer(move(numberGenerator4), language, 16);

  unique_ptr<Evaluator> evaluator = make_unique<FakeEvaluator>();
  unique_ptr<FitnessCalculator> calculator = make_unique<FakeFitnessCalculator>();

  auto processor = make_unique<Processor>(move(evaluator), move(calculator));

  Evolution evolution(move(processor));

  Population population = initializer.initialize(1000, reproducer);

  Individual result = evolution.run(population, 12345);

  double fitness = result.fitness();

  ASSERT_NEAR(0.0, fitness, 0.001);
}
