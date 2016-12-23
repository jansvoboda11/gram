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
  Grammar parse(std::string rules);
 private:
  std::string nonTerminal();
  std::string equals();
  std::string terminal();
};
}
}

#endif // GRAM_LANGUAGE_BNF_RULE_PARSER
