#include "gram/language/grammar/ContextFreeGrammar.h"

#include <catch.hpp>

#include "gram/error/InvalidGrammar.h"
#include "gram/language/symbol/Rule.h"

using namespace gram;
using namespace std;

TEST_CASE("context-free grammar requires start rule", "[context-free_grammar]") {
  ContextFreeGrammar grammar;

  REQUIRE_THROWS_AS(grammar.startRule(), InvalidGrammar);
}

TEST_CASE("context-free grammar accepts rules", "[context-free_grammar]") {
  ContextFreeGrammar grammar;

  Rule rule1("rule1");
  Rule rule2("rule2");

  grammar.addRule(make_unique<Rule>("rule1"));
  grammar.addRule(make_unique<Rule>("rule2"));

  REQUIRE(grammar.startRule() == rule1);
  REQUIRE(grammar.ruleNamed("rule2") == rule2);
}

TEST_CASE("context-free grammar creates start rule", "[context-free_grammar]") {
  ContextFreeGrammar grammar;

  grammar.ruleNamed("start");

  REQUIRE(grammar.startRule().getName() == "start");
}
