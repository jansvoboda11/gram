#include "NonTerminalSymbol.h"

using namespace gram::language::grammar;

std::unique_ptr<Symbol> NonTerminalSymbol::expand(int possibilityNumber) {
  return std::make_unique<NonTerminalSymbol>();
}
