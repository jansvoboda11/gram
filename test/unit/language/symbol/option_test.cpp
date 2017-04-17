#include "gram/language/symbol/Option.h"

#include <catch.hpp>

#include "gram/language/symbol/NonTerminal.h"
#include "gram/language/symbol/Option.h"
#include "gram/language/symbol/Rule.h"
#include "gram/language/symbol/Terminal.h"

using namespace gram;
using namespace std;

TEST_CASE("option accepts terminals", "[option]") {
  Terminal terminal1("first");
  Terminal terminal2("second");

  auto terminal1Ptr = make_unique<Terminal>("first");
  auto terminal2Ptr = make_unique<Terminal>("second");

  Option option;
  option.addTerminal(move(terminal1Ptr));
  option.addTerminal(move(terminal2Ptr));

  REQUIRE(option.size() == 2);
  REQUIRE(option[0].isTerminal());
  REQUIRE(option[0].toTerminal().getValue() == "first");
  REQUIRE(option[1].isTerminal());
  REQUIRE(option[1].toTerminal().getValue() == "second");
}

TEST_CASE("option accepts a non-terminal", "[option]") {
  Rule rule("rule");
  auto nonTerminal = make_unique<NonTerminal>(rule);

  Option option;

  option.addNonTerminal(move(nonTerminal));

  REQUIRE(option.size() == 1);
  REQUIRE(option[0].isNonTerminal());
  REQUIRE(option[0].toNonTerminal().toRule().getName() == "rule");
}

TEST_CASE("option accepts both terminals and non-terminals", "[option]") {
  Rule rule("rule");
  auto nonTerminal = make_unique<NonTerminal>(rule);

  auto terminal = make_unique<Terminal>("terminal");

  Option option;

  option.addTerminal(move(terminal));
  option.addNonTerminal(move(nonTerminal));

  REQUIRE(option.size() == 2);
  REQUIRE(option[0].isTerminal());
  REQUIRE(option[0].toTerminal().getValue() == "terminal");
  REQUIRE(option[1].isNonTerminal());
  REQUIRE(option[1].toNonTerminal().toRule().getName() == "rule");
}
