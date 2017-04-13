#include <catch.hpp>

#include <gram/language/symbol/Option.h>
#include <gram/language/symbol/Rule.h>

using namespace gram;
using namespace std;

TEST_CASE("option accepts a terminal", "[option]") {
  auto terminal1 = make_shared<Terminal>("first");
  auto terminal2 = make_shared<Terminal>("second");

  Option option;
  option.addTerminal(terminal1);
  option.addTerminal(terminal2);

  REQUIRE(option.hasTerminalAt(0));
  REQUIRE(option.hasTerminalAt(1));
  REQUIRE(option.terminalAt(0) == terminal1);
  REQUIRE(option.terminalAt(1) == terminal2);
}

TEST_CASE("option accepts a non-terminal", "[option]") {
  auto rule = make_shared<Rule>("rule");
  auto nonTerminal = make_shared<NonTerminal>(rule);

  Option option;

  option.addNonTerminal(nonTerminal);

  REQUIRE(option.hasNonTerminalAt(0));
  REQUIRE(option.nonTerminalAt(0) == nonTerminal);
}

TEST_CASE("option accepts both terminals and non-terminals", "[option]") {
  auto terminal = make_shared<Terminal>("regular");

  auto rule = make_shared<Rule>("rule");
  auto nonTerminal = make_shared<NonTerminal>(rule);

  Option option;

  option.addTerminal(terminal);
  option.addNonTerminal(nonTerminal);

  REQUIRE(option.hasTerminalAt(0));
  REQUIRE(option.hasNonTerminalAt(1));
  REQUIRE(option.terminalAt(0) == terminal);
  REQUIRE(option.nonTerminalAt(1) == nonTerminal);
}

TEST_CASE("same options are equal", "[option]") {
  auto terminal1 = make_shared<Terminal>("test");
  auto terminal2 = make_shared<Terminal>("test");

  Option option1;
  Option option2;

  option1.addTerminal(terminal1);
  option2.addTerminal(terminal2);

  REQUIRE(option1 == option2);
}

TEST_CASE("different options are not equal", "[option]") {
  auto terminal1 = make_shared<Terminal>("first");
  auto terminal2 = make_shared<Terminal>("second");

  Option option1;
  Option option2;

  option1.addTerminal(terminal1);
  option2.addTerminal(terminal2);

  REQUIRE(option1 != option2);
}
