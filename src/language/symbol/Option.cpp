#include <gram/language/symbol/Option.h>

using namespace gram::language;

Option::Option() : symbolCount(0) {
  //
}

unsigned long Option::size() {
  return symbolCount;
}

void Option::addTerminal(Terminal terminal) {
  terminals.emplace(symbolCount, terminal);

  symbolCount += 1;
}

void Option::addNonTerminal(std::weak_ptr<NonTerminal> nonTerminal) {
  nonTerminals.emplace(symbolCount, nonTerminal);

  symbolCount += 1;
}

bool Option::hasNonTerminalAt(unsigned long index) {
  return nonTerminals.find(index) != nonTerminals.end();
}

bool Option::hasTerminalAt(unsigned long index) {
  return terminals.find(index) != terminals.end();
}

Terminal Option::terminalAt(unsigned long index) {
  return terminals.at(index);
}

std::weak_ptr<NonTerminal> Option::nonTerminalAt(unsigned long index) {
  return nonTerminals.at(index);
}

bool Option::operator==(const Option &option) const {
  for (unsigned long i = 0; i < symbolCount; i++) {
    if (terminals.find(i) != terminals.end()) {
      if (option.terminals.find(i) == option.terminals.end()) {
        return false;
      }

      if (terminals.at(i) != option.terminals.at(i)) {
        return false;
      }
    }

    if (nonTerminals.find(i) != nonTerminals.end()) {
      if (option.nonTerminals.find(i) == option.nonTerminals.end()) {
        return false;
      }

      if (*nonTerminals.at(i).lock() != *option.nonTerminals.at(i).lock()) {
        return false;
      }
    }
  }

  return true;
}

bool Option::operator!=(const Option &option) const {
  return !operator==(option);
}
