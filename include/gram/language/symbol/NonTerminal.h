#ifndef GRAM_LANGUAGE_NON_TERMINAL_SYMBOL
#define GRAM_LANGUAGE_NON_TERMINAL_SYMBOL

#include <memory>
#include <vector>

#include <gram/language/symbol/Symbol.h>

namespace gram {
// Forward declaration.
class Rule;
/**
 * Class.
 */
class NonTerminal : public Symbol {
 public:
  NonTerminal(Rule& rule);
  Rule& toRule() const;
  bool isTerminal() const;
  bool isNonTerminal() const;
  bool operator==(const NonTerminal& nonTerminal) const;
  bool operator!=(const NonTerminal& nonTerminal) const;
 private:
  Rule& rule;
};
}

#endif // GRAM_LANGUAGE_NON_TERMINAL_SYMBOL
