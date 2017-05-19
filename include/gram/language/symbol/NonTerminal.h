#ifndef GRAM_NON_TERMINAL
#define GRAM_NON_TERMINAL

#include "gram/language/symbol/Symbol.h"

namespace gram {
class Rule;
/**
 * Class.
 */
class NonTerminal : public Symbol {
public:
  NonTerminal(Rule& rule);
  Rule& toRule() const;
  bool isTerminal() const override;
  bool isNonTerminal() const override;
  bool operator==(const NonTerminal& nonTerminal) const;
  bool operator!=(const NonTerminal& nonTerminal) const;

private:
  Rule& rule;
};
}

#endif
