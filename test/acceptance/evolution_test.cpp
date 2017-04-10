#include <catch.hpp>
#include <fakeit.hpp>

#include <gram/individual/crossover/OnePointCrossover.h>
#include <gram/individual/mutation/NumberMutation.h>
#include <gram/language/parser/BnfRuleParser.h>
#include <gram/population/initializer/RandomInitializer.h>
#include <gram/population/selector/TournamentSelector.h>
#include <gram/util/bool_generator/TwisterBoolGenerator.h>
#include <gram/util/logger/NullLogger.h>
#include <gram/util/number_generator/TwisterNumberGenerator.h>
#include <gram/Evolution.h>

using namespace fakeit;
using namespace gram;
using namespace std;

class FakeEvaluator : public Evaluator {
 public:
  FakeEvaluator(string desired) : desired(desired) {}

  double evaluate(string program) {
    return static_cast<double>(edit_distance(program, desired));
  }

 private:
  string desired;

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

TEST_CASE("evolution_test") {
  auto numberGenerator1 = make_unique<TwisterNumberGenerator>();
  auto numberGenerator2 = make_unique<TwisterNumberGenerator>();
  auto numberGenerator3 = make_unique<TwisterNumberGenerator>();
  auto numberGenerator4 = make_unique<TwisterNumberGenerator>();
  auto boolGenerator = make_unique<TwisterBoolGenerator>(0.1);

  auto selector = make_unique<TournamentSelector>(20, move(numberGenerator1));
  auto mutation = make_unique<NumberMutation>(move(boolGenerator), move(numberGenerator2));
  auto crossover = make_unique<OnePointCrossover>(move(numberGenerator3));
  auto reproducer = make_shared<Reproducer>(move(selector), move(crossover), move(mutation));

  string grammarString =
      "<number> ::= <number> <digit> | <digit>\n"
          "<digit> ::= \"0\" | \"1\" | \"2\" | \"3\" | \"4\" | \"5\" | \"6\" | \"7\" | \"8\" | \"9\"";

  BnfRuleParser parser;

  auto grammar = make_shared<ContextFreeGrammar>(parser.parse(grammarString));

  RandomInitializer initializer(move(numberGenerator4), grammar, 16);

  auto evaluator = make_unique<FakeEvaluator>("1234");
  auto logger = make_unique<NullLogger>();

  Evolution evolution(move(evaluator), move(logger));

  Population population = initializer.initialize(1000, reproducer);

  Individual result = evolution.run(population);

  double fitness = result.fitness();

  REQUIRE(fitness == 0.0);
}
