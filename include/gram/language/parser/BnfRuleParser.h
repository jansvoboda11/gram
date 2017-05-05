#ifndef GRAM_LANGUAGE_BNF_RULE_PARSER
#define GRAM_LANGUAGE_BNF_RULE_PARSER

#include <memory>
#include <string>

#include "gram/language/grammar/ContextFreeGrammar.h"
#include "gram/language/parser/RuleParser.h"
#include "gram/language/symbol/Option.h"

namespace gram {
/**
 * Class.
 */
class BnfRuleParser : public RuleParser {
public:
  ContextFreeGrammar parse(std::string input) const;

private:
  void parseRule(ContextFreeGrammar& grammar, std::string& line) const;
  std::unique_ptr<Option> parseOption(ContextFreeGrammar& grammar, std::string& line) const;
  bool parseNonTerminal(std::string& name, std::string& line) const;
  bool parseTerminal(std::string& value, std::string& line) const;
  bool parseEquals(std::string& line) const;
  bool parsePipe(std::string& line) const;
};
}

#endif // GRAM_LANGUAGE_BNF_RULE_PARSER
