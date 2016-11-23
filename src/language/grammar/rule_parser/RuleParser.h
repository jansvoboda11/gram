#ifndef GRAM_GRAMMAR_RULE_PARSER
#define GRAM_GRAMMAR_RULE_PARSER

#include "../Grammar.h"

namespace gram {
namespace language {
namespace grammar {
/**
 * Class.
 */
class RuleParser {
 public:
  virtual Grammar parse() = 0;
};
}
}
}

#endif // GRAM_GRAMMAR_RULE_PARSER
