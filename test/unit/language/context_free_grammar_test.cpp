#include <gtest/gtest.h>

#include <gram/language/ContextFreeGrammar.h>

using namespace gram;
using namespace std;

TEST(grammar_test, test_it_accepts_rule) {
  ContextFreeGrammar grammar;

  auto rule1 = make_shared<NonTerminal>();
  auto rule2 = make_shared<NonTerminal>();

  grammar.addRule("rule1", rule1);
  grammar.addRule("rule2", rule2);

  ASSERT_EQ(rule1, grammar.ruleNamed("rule1"));
  ASSERT_EQ(rule1, grammar.startRule());
}

TEST(grammar_test, test_it_expands_one_terminal) {
  Terminal terminal("test");
  auto option = make_shared<Option>();
  auto startSymbol = make_shared<NonTerminal>();

  option->addTerminal(terminal);
  startSymbol->addOption(option);

  ContextFreeGrammar grammar;
  grammar.addRule("rule", startSymbol);

  Genotype genotype({0});

  Phenotype expectedPhenotype;
  expectedPhenotype.addTerminal(terminal);

  ASSERT_EQ(expectedPhenotype, grammar.expand(genotype));
}

TEST(grammar_test, test_it_expands_nonterminal) {
  Terminal terminal1("first");
  Terminal terminal2("second");

  auto option1 = make_shared<Option>();
  auto option2 = make_shared<Option>();

  option1->addTerminal(terminal1);
  option2->addTerminal(terminal2);

  auto startSymbol = make_shared<NonTerminal>();

  startSymbol->addOption(option1);
  startSymbol->addOption(option2);

  ContextFreeGrammar grammar;
  grammar.addRule("rule", startSymbol);

  Genotype genotype{1};

  Phenotype expectedPhenotype;
  expectedPhenotype.addTerminal(terminal2);

  ASSERT_EQ(expectedPhenotype, grammar.expand(genotype));
}

TEST(grammar_test, test_it_expands_linear_grammar) {
  Terminal digit0("0");
  Terminal digit1("1");
  Terminal digit2("2");
  Terminal digit3("3");
  Terminal digit4("4");
  Terminal digit5("5");
  Terminal digit6("6");
  Terminal digit7("7");
  Terminal digit8("8");
  Terminal digit9("9");

  auto option0 = make_shared<Option>();
  auto option1 = make_shared<Option>();
  auto option2 = make_shared<Option>();
  auto option3 = make_shared<Option>();
  auto option4 = make_shared<Option>();
  auto option5 = make_shared<Option>();
  auto option6 = make_shared<Option>();
  auto option7 = make_shared<Option>();
  auto option8 = make_shared<Option>();
  auto option9 = make_shared<Option>();

  option0->addTerminal(digit0);
  option1->addTerminal(digit1);
  option2->addTerminal(digit2);
  option3->addTerminal(digit3);
  option4->addTerminal(digit4);
  option5->addTerminal(digit5);
  option6->addTerminal(digit6);
  option7->addTerminal(digit7);
  option8->addTerminal(digit8);
  option9->addTerminal(digit9);

  auto digit = make_shared<NonTerminal>();
  digit->addOption(option0);
  digit->addOption(option1);
  digit->addOption(option2);
  digit->addOption(option3);
  digit->addOption(option4);
  digit->addOption(option5);
  digit->addOption(option6);
  digit->addOption(option7);
  digit->addOption(option8);
  digit->addOption(option9);

  auto startSymbol = make_shared<NonTerminal>();

  auto digitOption = make_shared<Option>();
  digitOption->addNonTerminal(digit);

  auto numberOption = make_shared<Option>();
  numberOption->addNonTerminal(digit);
  numberOption->addNonTerminal(startSymbol);

  startSymbol->addOption(digitOption);
  startSymbol->addOption(numberOption);

  ContextFreeGrammar grammar;
  grammar.addRule("number", startSymbol);
  grammar.addRule("digit", digit);

  Phenotype phenotype = grammar.expand(Genotype({7, 16, 11, 25, 0, 39}));

  ASSERT_EQ("659", phenotype.serialize());
}
