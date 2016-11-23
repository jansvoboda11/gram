#include "Grammar.h"

using namespace gram::language::grammar;

std::unique_ptr<Symbol> Grammar::getStartSymbol() {
  return std::unique_ptr<Symbol>();
}
