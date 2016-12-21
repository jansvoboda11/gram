#ifndef GRAM_GRAMMAR_RULE_PARSER
#define GRAM_GRAMMAR_RULE_PARSER

#include <gram/language/Grammar.h>

namespace gram {
namespace grammar {
/**
 * Interface.
 */
class RuleParser {
 public:
  virtual Grammar parse(std::string rules) = 0;
};
}
}

#endif // GRAM_GRAMMAR_RULE_PARSER
