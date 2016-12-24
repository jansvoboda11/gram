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
  Grammar grammar;
  std::vector<std::string> lines;
  std::string line;
  std::shared_ptr<NonTerminal> rule;
  std::shared_ptr<NonTerminal> parseRule();
  std::shared_ptr<Option> parseOption();

  std::string nonTerminal();
  std::string equals();
  std::string terminal();
  std::string pipe();
  std::vector<std::string> explode(std::string string, std::string delimiter);
};
}
}

#endif // GRAM_LANGUAGE_BNF_RULE_PARSER
