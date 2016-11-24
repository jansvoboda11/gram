#include <gtest/gtest.h>

#include <language/grammar/symbol/Terminal.h>
#include <language/grammar/symbol/NonTerminal.h>
#include <language/grammar/Rule.h>
#include <language/grammar/Grammar.h>

using namespace gram::language::grammar;

TEST(grammar_test, test_it_accepts_start_rule) {
  Terminal terminal("test");

  Rule rule;
  rule.addTerminal(terminal);

  Grammar grammar(rule);

  ASSERT_EQ(rule, grammar.getStartRule());
}
