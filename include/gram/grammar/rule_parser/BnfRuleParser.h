#ifndef GRAM_GRAMMAR_RULE_PARSER_BFN
#define GRAM_GRAMMAR_RULE_PARSER_BFN

#include <gram/grammar/rule_parser/RuleParser.h>

namespace gram {
namespace grammar {
/**
 * Class.
 */
class BnfRuleParser : public RuleParser {
 public:
  BnfRuleParser(std::string rules);
  Grammar parse();
 private:
  std::string input;
};
}
}

#endif // GRAM_GRAMMAR_RULE_PARSER_BFN
