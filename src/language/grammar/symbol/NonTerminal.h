#ifndef GRAM_LANGUAGE_GRAMMAR_NON_TERMINAL
#define GRAM_LANGUAGE_GRAMMAR_NON_TERMINAL

#include <vector>

#include <language/grammar/Rule.h>

namespace gram {
namespace language {
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
}

#endif // GRAM_LANGUAGE_GRAMMAR_NON_TERMINAL
