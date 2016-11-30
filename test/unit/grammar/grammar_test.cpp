#include <gtest/gtest.h>

#include <gram/grammar/Grammar.h>

using namespace gram::grammar;

TEST(grammar_test, test_it_accepts_start_rule) {
  Terminal terminal("test");

  Rule rule;
  rule.addTerminal(terminal);

  Grammar grammar(rule);

  ASSERT_EQ(rule, grammar.getStartRule());
}
