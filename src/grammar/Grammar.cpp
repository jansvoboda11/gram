#include <gram/grammar/Grammar.h>

using namespace gram::grammar;

Grammar::Grammar(std::shared_ptr<NonTerminal> startSymbol) : startSymbol(startSymbol) {
  //
}

std::shared_ptr<NonTerminal> Grammar::getStartSymbol() {
  return startSymbol.lock();
}
