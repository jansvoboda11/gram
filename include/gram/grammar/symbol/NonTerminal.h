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
  void addRule(std::weak_ptr<Rule> rule);
  std::shared_ptr<Rule> ruleAt(unsigned long index);
  unsigned long ruleCount();
  bool operator==(const NonTerminal &nonTerminal) const;
  bool operator!=(const NonTerminal &nonTerminal) const;
 private:
  std::vector<std::weak_ptr<Rule>> rules;
};
}
}

#endif // GRAM_GRAMMAR_SYMBOL_NON_TERMINAL
