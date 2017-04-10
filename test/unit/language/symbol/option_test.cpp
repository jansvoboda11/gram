#include <catch.hpp>

#include <gram/language/symbol/Option.h>

using namespace gram;
using namespace std;

TEST_CASE("option accepts a terminal", "[option]") {
  Terminal terminal1("first");
  Terminal terminal2("second");

  Option option;
  option.addTerminal(terminal1);
  option.addTerminal(terminal2);

  REQUIRE(option.hasTerminalAt(0));
  REQUIRE(option.hasTerminalAt(1));
  REQUIRE(option.terminalAt(0) == terminal1);
  REQUIRE(option.terminalAt(1) == terminal2);
}

TEST_CASE("option accepts a non-terminal", "[option]") {
  Terminal terminal("terminal");

  auto innerOption = make_shared<Option>();
  auto nonTerminal = make_shared<NonTerminal>();

  innerOption->addTerminal(terminal);
  nonTerminal->addOption(innerOption);

  Option option;

  option.addNonTerminal(nonTerminal);

  REQUIRE(option.hasNonTerminalAt(0));
  REQUIRE(option.nonTerminalAt(0) == *nonTerminal);
}

TEST_CASE("option accepts both terminals and non-terminals", "[option]") {
  Terminal terminal("regular");
  Terminal innerTerminal("inner");

  auto innerOption = make_shared<Option>();
  auto nonTerminal = make_shared<NonTerminal>();

  innerOption->addTerminal(innerTerminal);
  nonTerminal->addOption(innerOption);

  Option option;

  option.addTerminal(terminal);
  option.addNonTerminal(nonTerminal);

  REQUIRE(option.hasTerminalAt(0));
  REQUIRE(option.hasNonTerminalAt(1));
  REQUIRE(option.terminalAt(0) == terminal);
  REQUIRE(option.nonTerminalAt(1) == *nonTerminal);
}

TEST_CASE("same options are equal", "[option]") {
  Terminal terminal1("test");
  Terminal terminal2("test");

  Option option1;
  Option option2;

  option1.addTerminal(terminal1);
  option2.addTerminal(terminal2);

  REQUIRE(option1 == option2);
}

TEST_CASE("different options are not equal", "[option]") {
  Terminal terminal1("first");
  Terminal terminal2("second");

  Option option1;
  Option option2;

  option1.addTerminal(terminal1);
  option2.addTerminal(terminal2);

  REQUIRE(option1 != option2);
}
