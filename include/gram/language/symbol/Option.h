#ifndef GRAM_LANGUAGE_OPTION
#define GRAM_LANGUAGE_OPTION

#include <memory>

#include <gram/language/symbol/NonTerminal.h>
#include <gram/language/symbol/Terminal.h>

namespace gram {
/**
 * Class.
 */
class Option {
 public:
  void addNonTerminal(std::shared_ptr<NonTerminal> nonTerminal);
  void addTerminal(std::shared_ptr<Terminal> terminal);
  bool hasNonTerminalAt(unsigned long index) const;
  bool hasTerminalAt(unsigned long index) const;
  std::shared_ptr<NonTerminal> nonTerminalAt(unsigned long index) const;
  std::shared_ptr<Terminal> terminalAt(unsigned long index) const;
  unsigned long size() const;
  bool operator==(const Option& option) const;
  bool operator!=(const Option& option) const;
 private:
  std::vector<std::shared_ptr<Symbol>> symbols;
};
}

#endif // GRAM_LANGUAGE_OPTION
