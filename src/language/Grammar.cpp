#include <gram/language/Grammar.h>

using namespace gram::language;

Grammar::Grammar(std::shared_ptr<NonTerminal> startSymbol) : start(startSymbol) {
  //
}

std::shared_ptr<NonTerminal> Grammar::startSymbol() const {
  if (!start) {
    throw std::logic_error("The start symbol of grammar is invalid.");
  }

  return start;
}
