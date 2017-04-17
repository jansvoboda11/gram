#ifndef GRAM_LANGUAGE_TERMINAL_SYMBOL
#define GRAM_LANGUAGE_TERMINAL_SYMBOL

#include "gram/language/symbol/Symbol.h"

#include <string>

namespace gram {
/**
 * Class.
 */
class Terminal : public Symbol {
 public:
  Terminal(std::string value);
  std::string getValue() const;
  bool isTerminal() const;
  bool isNonTerminal() const;
  bool operator==(const Terminal& terminal) const;
  bool operator!=(const Terminal& terminal) const;
 private:
  std::string value;
};
}

#endif // GRAM_LANGUAGE_TERMINAL_SYMBOL
