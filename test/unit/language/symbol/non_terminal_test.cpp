#include <catch.hpp>

#include <gram/language/symbol/NonTerminal.h>
#include <gram/language/symbol/Rule.h>

using namespace gram;
using namespace std;

TEST_CASE("non-terminal accepts a rule", "[non-terminal]") {
  Rule rule("rule");

  NonTerminal nonTerminal(rule);

  REQUIRE(nonTerminal.toRule() == rule);
}

TEST_CASE("same non-terminals are equal", "[non-terminal]") {
  Rule rule1("test");
  Rule rule2("test");

  NonTerminal nonTerminal1(rule1);
  NonTerminal nonTerminal2(rule2);

  REQUIRE(nonTerminal1 == nonTerminal2);
}

TEST_CASE("different non-terminals are not equal", "[non-terminal]") {
  Rule rule1("rule1");
  Rule rule2("rule2");

  NonTerminal nonTerminal1(rule1);
  NonTerminal nonTerminal2(rule2);

  REQUIRE(nonTerminal1 != nonTerminal2);
}
