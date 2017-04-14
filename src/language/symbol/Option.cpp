#include <gram/language/symbol/Option.h>

using namespace gram;
using namespace std;

void Option::addNonTerminal(shared_ptr<NonTerminal> nonTerminal) {
  symbols.push_back(nonTerminal);
}

void Option::addTerminal(shared_ptr<Terminal> terminal) {
  symbols.push_back(terminal);
}

bool Option::hasNonTerminalAt(unsigned long index) const {
  return index < symbols.size() && symbols[index]->isNonTerminal();
}

bool Option::hasTerminalAt(unsigned long index) const {
  return index < symbols.size() && symbols[index]->isTerminal();
}

shared_ptr<Terminal> Option::terminalAt(unsigned long index) const {
  return dynamic_pointer_cast<Terminal>(symbols.at(index));
}

shared_ptr<NonTerminal> Option::nonTerminalAt(unsigned long index) const {
  return dynamic_pointer_cast<NonTerminal>(symbols.at(index));
}

vector<shared_ptr<Symbol>> Option::getSymbols() {
  return symbols;
}

unsigned long Option::size() const {
  return symbols.size();
}

bool Option::operator==(const Option& option) const {
  if (symbols.size() != option.symbols.size()) {
    return false;
  }

  for (unsigned long i = 0; i < symbols.size(); i++) {
    if (hasTerminalAt(i)) {
      if (!option.hasTerminalAt(i)) {
        return false;
      }

      if (*terminalAt(i) != *option.terminalAt(i)) {
        return false;
      }
    }

    if (hasNonTerminalAt(i)) {
      if (!option.hasNonTerminalAt(i)) {
        return false;
      }

      if (*nonTerminalAt(i) != *option.nonTerminalAt(i)) {
        return false;
      }
    }
  }

  return true;
}

bool Option::operator!=(const Option& option) const {
  return !operator==(option);
}
