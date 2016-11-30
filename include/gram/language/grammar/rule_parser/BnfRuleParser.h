#ifndef GRAM_LANGUAGE_GRAMMAR_RULE_PARSER_BFN_RULE_PARSER
#define GRAM_LANGUAGE_GRAMMAR_RULE_PARSER_BFN_RULE_PARSER

#include <gram/language/grammar/rule_parser/RuleParser.h>

namespace gram {
namespace language {
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
}

#endif // GRAM_LANGUAGE_GRAMMAR_RULE_PARSER_BFN_RULE_PARSER
