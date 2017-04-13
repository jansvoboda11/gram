#include <catch.hpp>

#include <gram/language/symbol/NonTerminal.h>
#include <gram/language/symbol/Rule.h>

using namespace gram;
using namespace std;

TEST_CASE("non-terminal accepts a rule", "[non-terminal]") {
  auto rule = make_shared<Rule>("rule");

  NonTerminal nonTerminal(rule);

  REQUIRE(nonTerminal.toRule() == *rule);
}

TEST_CASE("same non-terminals are equal", "[non-terminal]") {
  auto rule1 = make_shared<Rule>("test");
  auto rule2 = make_shared<Rule>("test");

  NonTerminal nonTerminal1(rule1);
  NonTerminal nonTerminal2(rule2);

  REQUIRE(nonTerminal1 == nonTerminal2);
}

TEST_CASE("different non-terminals are not equal", "[non-terminal]") {
  auto rule1 = make_shared<Rule>("rule1");
  auto rule2 = make_shared<Rule>("rule2");

  NonTerminal nonTerminal1(rule1);
  NonTerminal nonTerminal2(rule2);

  REQUIRE(nonTerminal1 != nonTerminal2);
}
