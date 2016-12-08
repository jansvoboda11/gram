#include <gtest/gtest.h>

#include <gram/grammar/Grammar.h>

using namespace gram::grammar;

TEST(grammar_test, test_it_accepts_start_symbol) {
  auto startSymbol = std::make_shared<NonTerminal>();

  Grammar grammar(startSymbol);

  ASSERT_EQ(startSymbol, grammar.getStartSymbol());
}
