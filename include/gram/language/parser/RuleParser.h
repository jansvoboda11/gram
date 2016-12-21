#ifndef GRAM_LANGUAGE_RULE_PARSER
#define GRAM_LANGUAGE_RULE_PARSER

#include <gram/language/Grammar.h>

namespace gram {
namespace language {
/**
 * Interface.
 */
class RuleParser {
 public:
  virtual Grammar parse(std::string rules) = 0;
};
}
}

#endif // GRAM_LANGUAGE_RULE_PARSER
