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
  bool parseNonTerminal(std::string& name, std::string& line) const;
  bool parseTerminal(std::string& value, std::string& line) const;
  bool parseEquals(std::string& line) const;
  bool parsePipe(std::string& line) const;
};
}

#endif // GRAM_LANGUAGE_BNF_RULE_PARSER
