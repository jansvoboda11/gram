#include <gtest/gtest.h>
#include <gtest/fakeit.hpp>

#include <gram/individual/operator/NumberMutation.h>
#include <gram/individual/operator/OnePointCrossover.h>
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
  double evaluate(string program) const {
    return static_cast<double>(edit_distance(program, "1234"));
  }

  unsigned long edit_distance(const string& s1, const string& s2) const {
    const unsigned long len1 = s1.size(), len2 = s2.size();
    vector<vector<unsigned long>> d(len1 + 1, vector<unsigned long>(len2 + 1));

    d[0][0] = 0;

    for (unsigned int i = 1; i <= len1; ++i) {
      d[i][0] = i;
    }

    for (unsigned int i = 1; i <= len2; ++i) {
      d[0][i] = i;
    }

    for (unsigned int i = 1; i <= len1; ++i) {
      for (unsigned int j = 1; j <= len2; ++j) {
        d[i][j] = min({d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1)});
      }
    }

    return d[len1][len2];
  }
};

TEST(evolution_test, test_something) {
  unique_ptr<NumberGenerator> numberGenerator1 = make_unique<TwisterNumberGenerator>();
  unique_ptr<NumberGenerator> numberGenerator2 = make_unique<TwisterNumberGenerator>();
  unique_ptr<NumberGenerator> numberGenerator3 = make_unique<TwisterNumberGenerator>();
  unique_ptr<NumberGenerator> numberGenerator4 = make_unique<TwisterNumberGenerator>();
  unique_ptr<BoolGenerator> boolGenerator = make_unique<TwisterBoolGenerator>(0.1);

  auto selector = make_unique<TournamentSelector>(move(numberGenerator1));
  auto mutation = make_unique<NumberMutation>(move(boolGenerator), move(numberGenerator2));
  auto crossover = make_unique<OnePointCrossover>(move(numberGenerator3));
  auto reproducer = make_shared<Reproducer>(move(selector), move(crossover), move(mutation));

  string grammarString =
      "<number> ::= <number> <digit> | <digit>\n"
          "<digit> ::= \"0\" | \"1\" | \"2\" | \"3\" | \"4\" | \"5\" | \"6\" | \"7\" | \"8\" | \"9\"";

  BnfRuleParser parser;

  auto grammar = make_shared<ContextFreeGrammar>(parser.parse(grammarString));

  RandomInitializer initializer(move(numberGenerator4), grammar, 16);

  unique_ptr<Evaluator> evaluator = make_unique<FakeEvaluator>();

  Evolution evolution(move(evaluator));

  Population population = initializer.initialize(1000, reproducer);

  Individual result = evolution.run(population);

  double fitness = result.fitness();

  ASSERT_NEAR(0.0, fitness, 0.001);
}
