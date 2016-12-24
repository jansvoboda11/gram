#include <gtest/gtest.h>

#include <gram/language/Grammar.h>

using namespace gram::language;

TEST(grammar_test, test_it_accepts_rule) {
  Grammar grammar;

  auto rule1 = std::make_shared<NonTerminal>();
  auto rule2 = std::make_shared<NonTerminal>();

  grammar.addRule("rule1", rule1);
  grammar.addRule("rule2", rule2);

  ASSERT_TRUE(grammar.hasRuleNamed("rule1"));
  ASSERT_EQ(rule1, grammar.ruleNamed("rule1"));
  ASSERT_EQ(rule1, grammar.startRule());
}
