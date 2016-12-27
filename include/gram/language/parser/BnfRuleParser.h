#ifndef GRAM_LANGUAGE_BNF_RULE_PARSER
#define GRAM_LANGUAGE_BNF_RULE_PARSER

#include <regex>

#include <gram/language/parser/RuleParser.h>

namespace gram {
/**
 * Class.
 */
class BnfRuleParser : public RuleParser {
 public:
  Grammar parse(std::string input) const;
 private:
  void parseRule(Grammar& grammar, std::string& line) const;
  Option parseOption(Grammar& grammar, std::string& line) const;
  std::string nonTerminal() const;
  std::string equals() const;
  std::string terminal() const;
  std::string pipe() const;
};
}

#endif // GRAM_LANGUAGE_BNF_RULE_PARSER
