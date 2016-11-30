#ifndef GRAM_GRAMMAR_SYMBOL_NON_TERMINAL
#define GRAM_GRAMMAR_SYMBOL_NON_TERMINAL

#include <vector>

#include <gram/grammar/Rule.h>

namespace gram {
namespace grammar {
// Forward declaration.
class Rule;
/**
 * Class.
 */
class NonTerminal {
 public:
  void addRule(Rule &rule);
  Rule &ruleAt(int index);
  bool operator==(const NonTerminal &nonTerminal) const;
  bool operator!=(const NonTerminal &nonTerminal) const;
 private:
  std::vector<Rule *> rules;
};
}
}

#endif // GRAM_GRAMMAR_SYMBOL_NON_TERMINAL
