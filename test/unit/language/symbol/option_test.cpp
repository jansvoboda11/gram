#include "gram/language/symbol/Option.h"

#include <catch.hpp>

#include "gram/language/symbol/Rule.h"

using namespace gram;
using namespace std;

TEST_CASE("option accepts a terminal", "[option]") {
  Terminal terminal1("first");
  Terminal terminal2("second");

  auto terminal1Ptr = make_unique<Terminal>("first");
  auto terminal2Ptr = make_unique<Terminal>("second");

  Option option;
  option.addTerminal(move(terminal1Ptr));
  option.addTerminal(move(terminal2Ptr));

  REQUIRE(option.size() == 2);
}

TEST_CASE("option accepts a non-terminal", "[option]") {
  Rule rule("rule");
  auto nonTerminal = make_unique<NonTerminal>(rule);

  Option option;

  option.addNonTerminal(move(nonTerminal));

  REQUIRE(option.size() == 1);
}

TEST_CASE("option accepts both terminals and non-terminals", "[option]") {
  Rule rule("rule");
  auto nonTerminal = make_unique<NonTerminal>(rule);

  auto terminal = make_unique<Terminal>("regular");

  Option option;

  option.addTerminal(move(terminal));
  option.addNonTerminal(move(nonTerminal));

  REQUIRE(option.size() == 2);
}
