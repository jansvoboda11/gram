#include "gram/language/grammar/ContextFreeGrammar.h"

#include <catch.hpp>

using namespace gram;
using namespace std;

TEST_CASE("context-free grammar accepts rules", "[context-free_grammar]") {
  ContextFreeGrammar grammar;

  Rule rule1("rule1");
  Rule rule2("rule2");

  grammar.addRule(make_unique<Rule>("rule1"));
  grammar.addRule(make_unique<Rule>("rule2"));

  REQUIRE(grammar.startRule() == rule1);
  REQUIRE(grammar.ruleNamed("rule2") == rule2);
}
