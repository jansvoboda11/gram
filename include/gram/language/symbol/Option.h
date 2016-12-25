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
  bool hasNonTerminalAt(unsigned long index);
  bool hasTerminalAt(unsigned long index);
  std::weak_ptr<NonTerminal> nonTerminalAt(unsigned long index);
  Terminal terminalAt(unsigned long index);
  unsigned long size();
  bool operator==(const Option &option) const;
  bool operator!=(const Option &option) const;
 private:
  std::unordered_map<unsigned long, std::weak_ptr<NonTerminal>> nonTerminals;
  std::unordered_map<unsigned long, Terminal> terminals;
  unsigned long symbolCount;
};
}

#endif // GRAM_LANGUAGE_OPTION
