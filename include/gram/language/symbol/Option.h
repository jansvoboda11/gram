#ifndef GRAM_LANGUAGE_OPTION
#define GRAM_LANGUAGE_OPTION

#include <memory>
#include <vector>

#include "gram/language/symbol/NonTerminal.h"
#include "gram/language/symbol/Symbol.h"
#include "gram/language/symbol/Terminal.h"

namespace gram {
/**
 * Class.
 */
class Option {
 public:
  void addNonTerminal(std::unique_ptr<NonTerminal> nonTerminal);
  void addTerminal(std::unique_ptr<Terminal> terminal);
  Symbol& operator[](unsigned long index) const;
  unsigned long size() const;
  bool operator==(const Option& option) const;
  bool operator!=(const Option& option) const;
 private:
  std::vector<std::unique_ptr<Symbol>> symbols;
};
}

#endif // GRAM_LANGUAGE_OPTION
