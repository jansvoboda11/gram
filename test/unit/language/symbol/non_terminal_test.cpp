#include <catch.hpp>

#include <gram/language/symbol/NonTerminal.h>

using namespace gram;
using namespace std;

TEST_CASE("non-terminal accepts an option", "[non-terminal]") {
  Terminal terminal("test");

  auto option = make_shared<Option>();
  option->addTerminal(terminal);

  NonTerminal nonTerminal;

  nonTerminal.addOption(option);

  REQUIRE(nonTerminal.optionAt(0) == *option);
}

TEST_CASE("non-terminal handles a recursive option", "[non-terminal]") {
  Terminal terminal("test");

  auto option = make_shared<Option>();
  option->addTerminal(terminal);

  auto nonTerminal = make_shared<NonTerminal>();

  nonTerminal->addOption(option);
  option->addNonTerminal(nonTerminal);

  REQUIRE(nonTerminal->optionAt(0).hasNonTerminalAt(1));
  REQUIRE(nonTerminal->optionAt(0).nonTerminalAt(1) == *nonTerminal);
}

TEST_CASE("non-terminal returns option count", "[non-terminal]") {
  auto option1 = make_shared<Option>();
  auto option2 = make_shared<Option>();

  NonTerminal nonTerminal;

  nonTerminal.addOption(option1);
  nonTerminal.addOption(option2);

  REQUIRE(nonTerminal.size() == 2);
}

TEST_CASE("same non-terminals are equal", "[non-terminal]") {
  Terminal terminal("test");

  auto option = make_shared<Option>();
  option->addTerminal(terminal);

  NonTerminal nonTerminal1;
  NonTerminal nonTerminal2;

  nonTerminal1.addOption(option);
  nonTerminal2.addOption(option);

  REQUIRE(nonTerminal1 == nonTerminal2);
}

TEST_CASE("different non-terminals are not equal", "[non-terminal]") {
  Terminal terminal1("first");
  Terminal terminal2("second");

  auto option1 = make_shared<Option>();
  auto option2 = make_shared<Option>();

  option1->addTerminal(terminal1);
  option2->addTerminal(terminal2);

  NonTerminal nonTerminal1;
  NonTerminal nonTerminal2;

  nonTerminal1.addOption(option1);
  nonTerminal2.addOption(option2);

  REQUIRE(nonTerminal1 != nonTerminal2);
}
