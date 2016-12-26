#ifndef GRAM_LANGUAGE_RULE_PARSER
#define GRAM_LANGUAGE_RULE_PARSER

#include <gram/language/Grammar.h>

namespace gram {
/**
 * Interface.
 */
class RuleParser {
 public:
  virtual std::shared_ptr<Grammar> parse(std::string input) const = 0;
};
}

#endif // GRAM_LANGUAGE_RULE_PARSER
