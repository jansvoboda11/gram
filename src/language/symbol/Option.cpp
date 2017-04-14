#include <gram/language/symbol/Option.h>

using namespace gram;
using namespace std;

void Option::addNonTerminal(unique_ptr<NonTerminal> nonTerminal) {
  symbolPointers.push_back(nonTerminal.get());
  symbols.push_back(move(nonTerminal));
}

void Option::addTerminal(unique_ptr<Terminal> terminal) {
  symbolPointers.push_back(terminal.get());
  symbols.push_back(move(terminal));
}

std::vector<Symbol*>::iterator Option::begin() {
  return symbolPointers.begin();
}

std::vector<Symbol*>::iterator Option::end() {
  return symbolPointers.end();
}

std::vector<Symbol*>::reverse_iterator Option::rbegin() {
  return symbolPointers.rbegin();
}

std::vector<Symbol*>::reverse_iterator Option::rend() {
  return symbolPointers.rend();
}

Symbol& Option::operator[](unsigned long index) {
  return *symbols[index];
}

unsigned long Option::size() const {
  return symbols.size();
}

bool Option::operator==(const Option& option) const {
//  if (symbols.size() != option.symbols.size()) {
//    return false;
//  }
//
//  for (unsigned long i = 0; i < symbols.size(); i++) {
//    if (hasTerminalAt(i)) {
//      if (!option.hasTerminalAt(i)) {
//        return false;
//      }
//
//      if (*terminalAt(i) != *option.terminalAt(i)) {
//        return false;
//      }
//    }
//
//    if (hasNonTerminalAt(i)) {
//      if (!option.hasNonTerminalAt(i)) {
//        return false;
//      }
//
//      if (*nonTerminalAt(i) != *option.nonTerminalAt(i)) {
//        return false;
//      }
//    }
//  }

  return true;
}

bool Option::operator!=(const Option& option) const {
  return !operator==(option);
}

