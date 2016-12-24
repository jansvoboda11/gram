#ifndef GRAM_LANGUAGE_BNF_RULE_PARSER
#define GRAM_LANGUAGE_BNF_RULE_PARSER

#include <regex>

#include <gram/language/parser/RuleParser.h>

namespace gram {
namespace language {
/**
 * Class.
 */
class BnfRuleParser : public RuleParser {
 public:
  Grammar parse(std::string input);
 private:
  std::vector<std::string> explode(std::string string, std::string delimiter);
  void parseRule(Grammar &grammar, std::string &line);
  std::shared_ptr<Option> parseOption(Grammar &grammar, std::string &line);
  std::string nonTerminal();
  std::string equals();
  std::string terminal();
  std::string pipe();
};
}
}

#endif // GRAM_LANGUAGE_BNF_RULE_PARSER
