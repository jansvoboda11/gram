#include <language/grammar/Rule.h>

using namespace gram::language::grammar;

Rule::Rule() : symbolCount(0) {
  //
}

int Rule::size() {
  return symbolCount;
}

void Rule::addTerminal(Terminal &terminal) {
  terminals[symbolCount] = &terminal;

  symbolCount += 1;
}

void Rule::addNonTerminal(NonTerminal &nonTerminal) {
  nonTerminals[symbolCount] = &nonTerminal;

  symbolCount += 1;
}

bool Rule::hasNonTerminalAt(int index) {
  std::unordered_map<int, NonTerminal *>::const_iterator hasItem = nonTerminals.find(index);

  return hasItem != nonTerminals.end();
}

bool Rule::hasTerminalAt(int index) {
  std::unordered_map<int, Terminal *>::const_iterator hasItem = terminals.find(index);

  return hasItem != terminals.end();
}
Terminal &Rule::terminalAt(int index) {
  return *terminals[index];
}

NonTerminal &Rule::nonTerminalAt(int index) {
  return *nonTerminals[index];
}

bool Rule::operator==(const Rule &rule) const {
  for (int i = 0; i < symbolCount; i++) {
    if (terminals.find(i) != terminals.end()) {
      if (rule.terminals.find(i) == rule.terminals.end()) {
        return false;
      }
      Terminal firstTerminal = *terminals.at(i);
      Terminal secondTerminal = *rule.terminals.at(i);
      if (firstTerminal != secondTerminal) {
        return false;
      }
    }
    if (nonTerminals.find(i) != nonTerminals.end()) {
      if (rule.nonTerminals.find(i) == rule.nonTerminals.end()) {
        return false;
      }
      NonTerminal firstNonTerminal = *nonTerminals.at(i);
      NonTerminal secondNonTerminal = *rule.nonTerminals.at(i);
      if (firstNonTerminal != secondNonTerminal) {
        return false;
      }
    }
  }

  return true;
}

bool Rule::operator!=(const Rule &rule) const {
  return !operator==(rule);
}
