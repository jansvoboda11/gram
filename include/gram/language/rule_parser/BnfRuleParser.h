#ifndef GRAM_GRAMMAR_RULE_PARSER_BFN
#define GRAM_GRAMMAR_RULE_PARSER_BFN

#include <gram/language/rule_parser/RuleParser.h>

namespace gram {
namespace grammar {
/**
 * Class.
 */
class BnfRuleParser : public RuleParser {
 public:
  Grammar parse(std::string rules);
};
}
}

#endif // GRAM_GRAMMAR_RULE_PARSER_BFN
