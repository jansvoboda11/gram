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
  const Terminal& toTerminal() const;
  const NonTerminal& toNonTerminal() const;
  virtual bool isTerminal() const = 0;
  virtual bool isNonTerminal() const = 0;
  bool operator==(const Symbol& symbol) const;
  bool operator!=(const Symbol& symbol) const;
};
}

#endif // GRAM_LANGUAGE_SYMBOL
