#include <gtest/gtest.h>

#include <gram/language/Grammar.h>

using namespace gram;
using namespace std;

TEST(grammar_test, test_it_accepts_rule) {
  Grammar grammar;

  auto rule1 = make_shared<NonTerminal>();
  auto rule2 = make_shared<NonTerminal>();

  grammar.addRule("rule1", rule1);
  grammar.addRule("rule2", rule2);

  ASSERT_EQ(rule1, grammar.ruleNamed("rule1"));
  ASSERT_EQ(rule1, grammar.startRule());
}
