#include "TerminalSymbol.h"

using namespace gram::language::grammar;

std::unique_ptr<Symbol> TerminalSymbol::expand(int possibilityNumber) {
  return std::make_unique<TerminalSymbol>();
}
