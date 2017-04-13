#ifndef GRAM_LANGUAGE_SYMBOL
#define GRAM_LANGUAGE_SYMBOL

namespace gram {
/**
 * Interface.
 */
class Symbol {
 public:
  virtual bool isTerminal() const = 0;
  virtual bool isNonTerminal() const = 0;
};
}

#endif // GRAM_LANGUAGE_SYMBOL
