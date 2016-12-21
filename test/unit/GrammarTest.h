#ifndef GRAM_GRAMMAR_TEST
#define GRAM_GRAMMAR_TEST

#include <gtest/gtest.h>

#include <gram/language/LanguageMock.h>
#include <gram/grammar/Grammar.h>
#include <gram/grammar/symbol/Terminal.h>

namespace {
class GrammarTest : public ::testing::Test {
 protected:
  void SetUp() {
    terminal = std::make_shared<gram::grammar::Terminal>("hello");
    option = std::make_shared<gram::grammar::Option>();
    option->addTerminal(*terminal);
    start = std::make_shared<gram::grammar::NonTerminal>();
    start->addOption(option);

    grammar = std::make_shared<gram::grammar::Grammar>(start);
    mapper = std::make_shared<gram::individual::Mapper>(*grammar);

    language = std::make_shared<::testing::NiceMock<gram::language::LanguageMock>>(*grammar, *mapper);

    phenotype = std::make_shared<gram::individual::Phenotype>();
    phenotype->addTerminal(*terminal);
  }

  std::shared_ptr<gram::grammar::Option> option;
  std::shared_ptr<gram::grammar::NonTerminal> start;
  std::shared_ptr<gram::individual::Phenotype> phenotype;
  std::shared_ptr<gram::grammar::Terminal> terminal;
  std::shared_ptr<gram::grammar::Grammar> grammar;
  std::shared_ptr<gram::individual::Mapper> mapper;
  std::shared_ptr<::testing::NiceMock<gram::language::LanguageMock>> language;
};
}

#endif // GRAM_GRAMMAR_TEST
