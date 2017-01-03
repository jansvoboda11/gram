#ifndef GRAM_LANGUAGE_RULE_PARSER
#define GRAM_LANGUAGE_RULE_PARSER

#include <gram/language/ContextFreeGrammar.h>

namespace gram {
/**
 * Interface.
 */
class RuleParser {
 public:
  virtual ContextFreeGrammar parse(std::string input) const = 0;
};
}

#endif // GRAM_LANGUAGE_RULE_PARSER
