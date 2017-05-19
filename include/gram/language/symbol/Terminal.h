#ifndef GRAM_TERMINAL
#define GRAM_TERMINAL

#include <string>

#include "gram/language/symbol/Symbol.h"

namespace gram {
/**
 * Class.
 */
class Terminal : public Symbol {
public:
  Terminal(std::string value);
  std::string getValue() const;
  bool isTerminal() const override;
  bool isNonTerminal() const override;
  bool operator==(const Terminal& terminal) const;
  bool operator!=(const Terminal& terminal) const;

private:
  std::string value;
};
}

#endif
