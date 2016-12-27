#ifndef GRAM_LANGUAGE_OPTION
#define GRAM_LANGUAGE_OPTION

#include <memory>
#include <unordered_map>

#include <gram/language/symbol/NonTerminal.h>
#include <gram/language/symbol/Terminal.h>

namespace gram {
// Forward declaration.
class NonTerminal;
/**
 * Class.
 */
class Option {
 public:
  Option();
  void addNonTerminal(std::weak_ptr<NonTerminal> nonTerminal);
  void addTerminal(Terminal terminal);
  bool hasNonTerminalAt(unsigned long index) const;
  bool hasTerminalAt(unsigned long index) const;
  NonTerminal& nonTerminalAt(unsigned long index) const;
  Terminal terminalAt(unsigned long index) const;
  unsigned long size() const;
  bool operator==(const Option &option) const;
  bool operator!=(const Option &option) const;
 private:
  std::unordered_map<unsigned long, std::weak_ptr<NonTerminal>> nonTerminals;
  std::unordered_map<unsigned long, Terminal> terminals;
  unsigned long symbolCount;
};
}

#endif // GRAM_LANGUAGE_OPTION
