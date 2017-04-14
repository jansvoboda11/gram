#ifndef GRAM_LANGUAGE_SYMBOL
#define GRAM_LANGUAGE_SYMBOL

namespace gram {
// Forward declarations.
class Terminal;
class NonTerminal;
/**
 * Abstract class.
 */
class Symbol {
 public:
  Terminal& toTerminal();
  NonTerminal& toNonTerminal();
  virtual bool isTerminal() const = 0;
  virtual bool isNonTerminal() const = 0;
};
}

#endif // GRAM_LANGUAGE_SYMBOL
