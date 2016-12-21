#ifndef GRAM_LANGUAGE_BNF_RULE_PARSER
#define GRAM_LANGUAGE_BNF_RULE_PARSER

#include <gram/language/parser/RuleParser.h>

namespace gram {
namespace language {
/**
 * Class.
 */
class BnfRuleParser : public RuleParser {
 public:
  Grammar parse(std::string rules);
};
}
}

#endif // GRAM_LANGUAGE_BNF_RULE_PARSER
