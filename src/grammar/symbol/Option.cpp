#include <gram/grammar/symbol/Option.h>

using namespace gram::grammar;

Option::Option() : symbolCount(0) {
  //
}

int Option::size() {
  return symbolCount;
}

void Option::addTerminal(Terminal &terminal) {
  terminals[symbolCount] = &terminal;

  symbolCount += 1;
}

void Option::addNonTerminal(std::shared_ptr<NonTerminal> nonTerminal) {
  nonTerminals[symbolCount] = nonTerminal;

  symbolCount += 1;
}

bool Option::hasNonTerminalAt(unsigned long index) {
  std::unordered_map<unsigned long, std::shared_ptr<NonTerminal>>::const_iterator hasItem = nonTerminals.find(index);

  return hasItem != nonTerminals.end();
}

bool Option::hasTerminalAt(unsigned long index) {
  std::unordered_map<unsigned long, Terminal *>::const_iterator hasItem = terminals.find(index);

  return hasItem != terminals.end();
}

Terminal &Option::terminalAt(unsigned long index) {
  return *terminals[index];
}

std::shared_ptr<NonTerminal> Option::nonTerminalAt(unsigned long index) {
  return nonTerminals[index];
}

bool Option::operator==(const Option &option) const {
  for (unsigned long i = 0; i < symbolCount; i++) {
    if (terminals.find(i) != terminals.end()) {
      if (option.terminals.find(i) == option.terminals.end()) {
        return false;
      }

      Terminal firstTerminal = *terminals.at(i);
      Terminal secondTerminal = *option.terminals.at(i);

      if (firstTerminal != secondTerminal) {
        return false;
      }
    }

    if (nonTerminals.find(i) != nonTerminals.end()) {
      if (option.nonTerminals.find(i) == option.nonTerminals.end()) {
        return false;
      }

      NonTerminal firstNonTerminal = *nonTerminals.at(i);
      NonTerminal secondNonTerminal = *option.nonTerminals.at(i);

      if (firstNonTerminal != secondNonTerminal) {
        return false;
      }
    }
  }

  return true;
}

bool Option::operator!=(const Option &option) const {
  return !operator==(option);
}
