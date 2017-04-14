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
  void addNonTerminal(std::unique_ptr<NonTerminal> nonTerminal);
  void addTerminal(std::unique_ptr<Terminal> terminal);
  std::vector<Symbol*>::iterator begin();
  std::vector<Symbol*>::iterator end();
  std::vector<Symbol*>::reverse_iterator rbegin();
  std::vector<Symbol*>::reverse_iterator rend();
  Symbol& operator[](unsigned long index);
  unsigned long size() const;
  bool operator==(const Option& option) const;
  bool operator!=(const Option& option) const;
 private:
  std::vector<std::unique_ptr<Symbol>> symbols;
  std::vector<Symbol*> symbolPointers;
};
}

#endif // GRAM_LANGUAGE_OPTION
