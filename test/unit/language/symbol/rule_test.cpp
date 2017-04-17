#include "gram/language/symbol/Rule.h"

#include <catch.hpp>

#include "gram/error/InvalidGrammar.h"
#include "gram/language/symbol/Option.h"
#include "gram/language/symbol/Terminal.h"

using namespace gram;
using namespace std;

TEST_CASE("rule requires a name", "[rule]") {
  REQUIRE_THROWS_AS(Rule(""), InvalidGrammar);
}

TEST_CASE("rule accepts an option", "[rule]") {
  auto terminal = make_unique<Terminal>("terminal");

  auto option = make_unique<Option>();
  option->addTerminal(move(terminal));

  Rule rule("rule");

  rule.addOption(move(option));

  REQUIRE(rule.size() == 1);
  REQUIRE(rule[0].size() == 1);
  REQUIRE(rule[0][0].isTerminal());
  REQUIRE(rule[0][0].toTerminal().getValue() == "terminal");
}
