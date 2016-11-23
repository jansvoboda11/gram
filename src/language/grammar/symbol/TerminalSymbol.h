#ifndef GRAM_LANGUAGE_GRAMMAR_TERMINAL_SYMBOL
#define GRAM_LANGUAGE_GRAMMAR_TERMINAL_SYMBOL

#include "Symbol.h"

namespace gram {
namespace language {
namespace grammar {
/**
 * Class.
 */
class TerminalSymbol : public Symbol {
 public:
  std::unique_ptr<Symbol> expand(int possibilityNumber);
};
}
}
}

#endif // GRAM_LANGUAGE_GRAMMAR_TERMINAL_SYMBOL
