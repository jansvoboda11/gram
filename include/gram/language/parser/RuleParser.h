#ifndef GRAM_RULE_PARSER
#define GRAM_RULE_PARSER

#include "gram/language/grammar/ContextFreeGrammar.h"

namespace gram {
/**
 * Interface.
 */
class RuleParser {
public:
  virtual ~RuleParser() = default;
  virtual ContextFreeGrammar parse(std::string input) const = 0;
};
}

#endif
