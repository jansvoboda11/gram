#include "gram/language/symbol/Option.h"

#include <algorithm>
#include <memory>

#include "gram/language/symbol/NonTerminal.h"
#include "gram/language/symbol/Terminal.h"

using namespace gram;
using namespace std;

void Option::addNonTerminal(unique_ptr<NonTerminal> nonTerminal) {
  symbols.push_back(move(nonTerminal));
}

void Option::addTerminal(unique_ptr<Terminal> terminal) {
  symbols.push_back(move(terminal));
}

Symbol& Option::operator[](unsigned long index) const {
  return *symbols[index];
}

unsigned long Option::size() const {
  return symbols.size();
}
