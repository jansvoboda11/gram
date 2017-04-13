#include <catch.hpp>

#include <gram/language/grammar/ContextFreeGrammar.h>

using namespace gram;
using namespace std;

TEST_CASE("context-free grammar accepts rules", "[context-free_grammar]") {
  ContextFreeGrammar grammar;

  auto rule1 = make_shared<Rule>("rule1");
  auto rule2 = make_shared<Rule>("rule2");

  grammar.addRule(rule1);
  grammar.addRule(rule2);

  REQUIRE(grammar.startRule() == rule1);
  REQUIRE(grammar.ruleNamed("rule2") == rule2);
}
