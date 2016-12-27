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
  std::shared_ptr<Grammar> parse(std::string input) const;
 private:
  void parseRule(std::shared_ptr<Grammar> grammar, std::string& line) const;
  Option parseOption(std::shared_ptr<Grammar> grammar, std::string& line) const;
  std::string nonTerminal() const;
  std::string equals() const;
  std::string terminal() const;
  std::string pipe() const;
};
}

#endif // GRAM_LANGUAGE_BNF_RULE_PARSER
