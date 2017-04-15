#include <gram/language/symbol/Option.h>

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

bool Option::operator==(const Option& option) const {
  if (size() != option.size()) {
    return false;
  }

  for (unsigned long i = 0; i < size(); i++) {
    if (*symbols[i] != *option.symbols[i]) {
      return false;
    }
  }

  return true;
}

bool Option::operator!=(const Option& option) const {
  return !operator==(option);
}
