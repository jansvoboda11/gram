#include <catch.hpp>

#include <gram/language/grammar/ContextFreeGrammar.h>

using namespace gram;
using namespace std;

TEST_CASE("context-free grammar accepts a rule", "[context-free_grammar]") {
  ContextFreeGrammar grammar;

  auto rule1 = make_shared<NonTerminal>();
  auto rule2 = make_shared<NonTerminal>();

  grammar.addRule("rule1", rule1);
  grammar.addRule("rule2", rule2);

  REQUIRE(grammar.ruleNamed("rule1") == rule1);
  REQUIRE(grammar.startRule() == rule1);
}
