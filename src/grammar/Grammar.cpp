#include <gram/language/Grammar.h>

using namespace gram::grammar;

Grammar::Grammar(std::shared_ptr<NonTerminal> startSymbol) : start(startSymbol) {
  //
}

std::shared_ptr<NonTerminal> Grammar::startSymbol() const {
  return start.lock();
}
